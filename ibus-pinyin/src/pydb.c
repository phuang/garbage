/* vim:set et sts=4: */
#include <string.h>
#include <glib.h>
#include <sqlite3.h>
#include <stdio.h>
#include <stdarg.h>
#include "pinyin.h"
#include "pydb.h"

#define DB_CACHE_SIZE "5000"

struct _PYDB {
    sqlite3 *db;
};

PYDB *
py_db_new ()
{
    PYDB *db = g_new0 (PYDB, 1);

    if (sqlite3_open_v2 ("py.db", &(db->db), SQLITE_OPEN_READONLY, NULL) != SQLITE_OK) {
        g_free (db);
        db = NULL;
    }

    if (sqlite3_exec (db->db, "PRAGMA cache_size=" DB_CACHE_SIZE, NULL, NULL, NULL) != SQLITE_OK) {
        return NULL;
    }

    return db;
}


void
py_db_free (PYDB *db)
{
#if 0
    sqlite3_stmt *stmt;

    while((stmt = sqlite3_next_stmt(db->db, NULL)) != NULL){
        sqlite3_finalize(stmt);
    }
#endif
    sqlite3_close (db->db);

    g_free (db);
}

static void
_conditions_append_vprintf (GArray      *array,
                            gint         begin,
                            gint         end,
                            const gchar *fmt,
                            va_list      args)
{
    gint i;
    GString *v;

    if (end - begin == 1) {
        v = g_array_index (array, GString *, begin);
        g_string_append_vprintf (v, fmt, args);
    }
    else {
        gchar str[64];
        vsnprintf (str, sizeof(str), fmt, args);
        for (i = begin; i < end; i++) {
            v = g_array_index (array, GString *, i);
            g_string_append (v, str);
        }
    }
}

static void
_conditions_append_printf (GArray      *array,
                           gint         begin,
                           gint         end,
                           const gchar *fmt,
                           ...)
{
    va_list args;
    va_start (args, fmt);
    _conditions_append_vprintf (array, begin, end, fmt, args);
    va_end (args);
}

static void
_conditions_double (GArray *array)
{
    gint i, len;

    for (i = 0, len = array->len; i < len; i++) {
        GString *v = g_array_index (array, GString *, i);
        v = g_string_new (v->str);
        g_array_append_val (array, v);
    }
}


gboolean
py_db_query_internal (PYDB          *db,
                      GArray        *pinyin,
                      gint           pinyin_begin,
                      gint           pinyin_len,
                      PYPhraseArray *result,
                      gint           m,
                      guint          option)
{
    GString *sql, *v;
    GArray *array;
    sqlite3_stmt *stmt;
    gint i;

    if (pinyin_len > pinyin->len - pinyin_begin)
        pinyin_len = pinyin->len - pinyin_begin;
    if (pinyin_len > 16)
        return FALSE;

    /* prepare sql */
    sql = g_string_new ("");
    g_string_append_printf (sql, " select * from main.py_phrase_%d where ", pinyin_len - 1);

    array = g_array_new (TRUE, TRUE, sizeof (GString *));
    v = g_string_new ("");
    g_array_append_val (array, v);


    for (i = 0; i < pinyin_len; i++) {
        PinYin *p;
        p = g_array_index (pinyin, PinYin *, i + pinyin_begin);

        if (i > 0)
            _conditions_append_printf (array, 0, array->len, " and ");

        if (p->yun_id == 0) {
            if (p->fsheng_id == 0) {
                _conditions_append_printf (array, 0, array->len, " s%d = %d ", i, p->sheng_id);
            }
            else {
                if (i < 3) {
                    _conditions_double (array);
                    _conditions_append_printf (array, 0, array->len  >> 1, " s%d = %d ", i, p->sheng_id);
                    _conditions_append_printf (array, array->len >> 1, array->len, " s%d = %d ", i, p->fsheng_id);
                }
                else {
                    _conditions_append_printf (array, 0, array->len, " s%d in ( %d, %d ) ", i, p->sheng_id, p->fsheng_id);
                }
            }
        }
        else {
            if (p->fsheng_id == 0) {
                _conditions_append_printf (array, 0, array->len, " s%d = %d ", i, p->sheng_id);
            }
            else {
                if (i < 3) {
                    _conditions_double (array);
                    _conditions_append_printf (array, 0, array->len  >> 1, " s%d = %d ", i, p->sheng_id);
                    _conditions_append_printf (array, array->len >> 1, array->len, " s%d = %d ", i, p->fsheng_id);
                }
                else {
                    _conditions_append_printf (array, 0, array->len, " s%d in ( %d, %d ) ", i, p->sheng_id, p->fsheng_id);
                }
            }

            if (p->fyun_id == 0) {
                _conditions_append_printf (array, 0, array->len, " and y%d = %d ", i, p->yun_id);
            }
            else {
                if (i < 3) {
                    _conditions_double (array);
                    _conditions_append_printf (array, 0, array->len  >> 1, " and y%d = %d ", i, p->yun_id);
                    _conditions_append_printf (array, array->len >> 1, array->len, " and y%d = %d ", i, p->fyun_id);
                }
                else {
                    _conditions_append_printf (array, 0, array->len, " and y%d in ( %d, %d ) ", i, p->yun_id, p->fyun_id);
                }
            }
        }
    }

    for (i = 0; i < array->len; i++) {
        GString *v;
        v = g_array_index (array, GString *, i);
        if (i > 0)
            g_string_append (sql, " or ");

        g_string_append_printf (sql, "( %s )", v->str);
        g_string_free (v, TRUE);
    }
    g_array_free (array, TRUE);

    g_string_append (sql, " order by freq desc ");
    // if (pinyin_len == pinyin->len)
    //     g_debug ("sql = %s", sql->str);

    if (m > 0) {
        g_string_append_printf (sql, " limit %d ", m);
    }

    /* query database */
    if (sqlite3_prepare (db->db, sql->str, -1, &stmt, NULL) != SQLITE_OK) {
        return FALSE;
    }

    while (sqlite3_step (stmt) == SQLITE_ROW) {
        PYPhrase *p;
        gint j;

        p = py_phrase_new ();

        strcpy (p->phrase, (gchar *) sqlite3_column_text (stmt, 0));
        p->freq = sqlite3_column_int (stmt, 1);
        p->len = pinyin->len;

        for (j = 0; j < pinyin_len; j++) {
            p->pinyin_id[j][0] = sqlite3_column_int (stmt, (j << 1) + 2);
            p->pinyin_id[j][1] = sqlite3_column_int (stmt, (j << 1) + 3);
        }
        py_phrase_array_append (result, p);
        py_phrase_unref (p);
    }

    sqlite3_finalize (stmt);
    return TRUE;
}

PYPhraseArray *
py_db_query (PYDB   *db,
             GArray *pinyin,
             gint    m,
             guint   option)
{
    PYPhraseArray *result;
    gint len;
    gint i;

    result = py_phrase_array_new ();
    len = MIN (pinyin->len, MAX_PHRASE_LEN);

    for (i = len; i > 0; i--) {
        if (m < 0) {
            py_db_query_internal (db, pinyin, 0, i, result, -1, option);
        }
        else {
            py_db_query_internal (db, pinyin, 0, i, result, m - py_phrase_array_len (result), option);
            if (py_phrase_array_len(result) >= m)
                break;
        }
    }
    return result;
}

#ifdef TEST

#include <sys/time.h>
#include <locale.h>

void
py_db_test (PYDB *db)
{
    gint retval;
    sqlite3_stmt *stmt;
    gchar *sql = "select * from (select phrase, s0, y0, s1, y1, max(freq) / 10000 as freq from py_phrase_1 where s0=24 and y0=468 and s1=1 and y1=20 group by phrase) order by freq desc";

    retval = sqlite3_prepare (db->db, sql, -1, &stmt, NULL);

    if (retval != SQLITE_OK)
        return;

    while ((retval = sqlite3_step (stmt)) == SQLITE_ROW) {
        gchar *text;
        gint64 freq;
        text = sqlite3_column_text (stmt, 0);
        freq = sqlite3_column_int64 (stmt, 1);
    }
    sqlite3_finalize (stmt);
}

int main ()
{
    struct timeval tv1, tv2;

    setlocale (LC_ALL, "");
    PYDB *db = py_db_new ();
    if (db == NULL)
        return 0;
    py_db_test (db);

    gettimeofday (&tv1, NULL);
    py_db_test (db);
    py_db_test (db);
    py_db_test (db);
    py_db_test (db);
    py_db_test (db);
    py_db_test (db);
    py_db_test (db);
    py_db_test (db);
    py_db_test (db);
    py_db_test (db);
    gettimeofday (&tv2, NULL);
    gdouble v = tv2.tv_sec - tv1.tv_sec;
    v = v * 1000000 + tv2.tv_usec - tv1.tv_usec;
    g_debug ("time=%lf", v / 1000 / 10);

    py_db_free (db);
    return 0;
}
#endif
