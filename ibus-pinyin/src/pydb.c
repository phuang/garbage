/* vim:set et sts=4: */
#include <string.h>
#include <glib.h>
#include <sqlite3.h>
#include "pinyin.h"
#include "pydb.h"


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

gboolean
py_db_query_internal (PYDB          *db,
                      GArray        *pinyin,
                      gint           pinyin_begin,
                      gint           pinyin_len,
                      PYPhraseArray *result,
                      gint           m)
{
    GString *sql;
    sqlite3_stmt *stmt;
    gint i;

    if (pinyin_len > pinyin->len - pinyin_begin)
        pinyin_len = pinyin->len - pinyin_begin;
    if (pinyin_len > 16)
        return FALSE;

    /* prepare sql */
    sql = g_string_new ("");
    g_string_append_printf (sql, " select * from main.py_phrase_%d where ", pinyin_len - 1);

    for (i = pinyin_begin; i < pinyin_begin + pinyin_len; i++) {
        struct pinyin_t *p;
        p = g_array_index (pinyin, struct pinyin_t *, i);

        if (i > 0)
            g_string_append_printf (sql, " and ");

        if (p->yun_id != 0)
            g_string_append_printf (sql, " (s%d = %d and y%d = %d) ", i, p->sheng_id, i, p->yun_id);
        else
            g_string_append_printf (sql, " (s%d = %d) ", i, p->sheng_id);
    }
    g_string_append (sql, " order by freq desc ");

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
             gint    m)
{
    PYPhraseArray *result;
    gint len;
    gint i;

    result = py_phrase_array_new ();
    len = MIN (pinyin->len, MAX_PHRASE_LEN);

    for (i = len; i > 0; i--) {
        if (m < 0) {
            py_db_query_internal (db, pinyin, 0, i, result, -1);
        }
        else {
            py_db_query_internal (db, pinyin, 0, i, result, m - py_phrase_array_len (result));
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
}
#endif
