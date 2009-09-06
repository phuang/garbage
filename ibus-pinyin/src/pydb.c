/* vim:set et sts=4: */
#include <string.h>
#include <glib.h>
#include <sqlite3.h>
#include <stdio.h>
#include <stdarg.h>
#include "pinyin.h"
#include "pydb.h"

#define DB_CACHE_SIZE "5000"
#define DB_INDEX_SIZE (3)

struct _PYDB {
    sqlite3 *db;
    GString *sql;
    GArray  *conditions;
    GArray  *strings;
};

PYDB *
py_db_new ()
{
    gchar *sql;
    gchar *userdb;
    gchar *errmsg;
    PYDB *db = g_new0 (PYDB, 1);

    sqlite3_initialize ();

    if (sqlite3_open_v2 ("py.db", &(db->db), SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL) != SQLITE_OK) {
        g_slice_free (PYDB, db);
        db = NULL;
        goto _out;
    }

    userdb = "/home/phuang/.cache/ibus/ibus-pinyin/user.db";
    sql = g_strdup_printf ("ATTACH DATABASE \"%s\" AS userdb;", userdb);
    if (sqlite3_exec (db->db, sql, NULL, NULL, &errmsg) != SQLITE_OK) {
        g_debug ("%s", errmsg);
        g_slice_free (PYDB, db);
        db = NULL;
        goto _out;
    }
    g_free (sql);

    if (sqlite3_exec (db->db, "PRAGMA cache_size=" DB_CACHE_SIZE, NULL, NULL, &errmsg) != SQLITE_OK) {
        g_debug ("%s", errmsg);
        sqlite3_free (errmsg);
        g_slice_free (PYDB, db);
        db = NULL;
        goto _out;
    }

    db->sql = g_string_sized_new (1024);
    db->conditions = g_array_sized_new (FALSE, FALSE, sizeof (GString *), 32);
    db->strings = g_array_sized_new (FALSE, FALSE, sizeof (GString *), 32);
_out:
    return db;
}


void
py_db_free (PYDB *db)
{
    gint i;

    for (i = 0; i < db->strings->len; i++ ) {
        g_string_free (g_array_index (db->strings, GString *, i), TRUE);
    }
    g_array_free (db->strings, TRUE);

    for (i = 0; i < db->conditions->len; i++ ) {
        g_string_free (g_array_index (db->conditions, GString *, i), TRUE);
    }
    g_array_free (db->conditions, TRUE);

    g_string_free (db->sql, TRUE);

    sqlite3_close (db->db);
    g_slice_free (PYDB, db);
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
    gchar str[64];

    vsnprintf (str, sizeof(str), fmt, args);
    for (i = begin; i < end; i++) {
        v = g_array_index (array, GString *, i);
        g_string_append (v, str);
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

#define CONDITION_INIT_SIZE (256)

static GString *
_py_db_get_string (PYDB     *db)
{
    GString *s;
    if (db->strings->len == 0) {
        s = g_string_sized_new (CONDITION_INIT_SIZE);
    }
    else {
        s = g_array_index (db->strings, GString *, db->strings->len - 1);
        g_array_set_size (db->strings, db->strings->len - 1);
    }
    return s;
}

static void
_py_db_put_string (PYDB     *db,
                   GString  *s)
{
    g_string_truncate (s, 0);
    g_array_append_val (db->strings, s);
}

static void
_conditions_double (PYDB *db)
{
    gint i, len;

    len = db->conditions->len;
    g_array_set_size (db->conditions, len << 1);

    for (i = 0; i < len; i++) {
        GString *v = g_array_index (db->conditions, GString *, i);
        g_array_index (db->conditions, GString *, i + len) = g_string_append (_py_db_get_string (db), v->str);
    }
}

static void
_conditions_triple (PYDB *db)
{
    gint i, len;

    len = db->conditions->len;
    g_array_set_size (db->conditions, (len << 1) + len);

    for (i = 0; i < len; i++) {
        GString *v = g_array_index (db->conditions, GString *, i);
        g_array_index (db->conditions, GString *, i + len) = g_string_append (_py_db_get_string (db), v->str);
        g_array_index (db->conditions, GString *, i + (len << 1)) = g_string_append (_py_db_get_string (db), v->str);
    }
}

static gboolean
pinyin_option_check_sheng (guint option, gint id, gint fid)
{
    switch ((id << 16) | fid) {
    case (PINYIN_ID_C << 16) | PINYIN_ID_CH:
        return (option & PINYIN_FUZZY_C_CH);
    case (PINYIN_ID_CH << 16) | PINYIN_ID_C:
        return (option & PINYIN_FUZZY_CH_C);
    case (PINYIN_ID_Z << 16) | PINYIN_ID_ZH:
        return (option & PINYIN_FUZZY_Z_ZH);
    case (PINYIN_ID_ZH << 16) | PINYIN_ID_Z:
        return (option & PINYIN_FUZZY_ZH_Z);
    case (PINYIN_ID_S << 16) | PINYIN_ID_SH:
        return (option & PINYIN_FUZZY_S_SH);
    case (PINYIN_ID_SH << 16) | PINYIN_ID_S:
        return (option & PINYIN_FUZZY_SH_S);
    case (PINYIN_ID_L << 16) | PINYIN_ID_N:
        return (option & PINYIN_FUZZY_L_N);
    case (PINYIN_ID_N << 16) | PINYIN_ID_L:
        return (option & PINYIN_FUZZY_N_L);
    case (PINYIN_ID_F << 16) | PINYIN_ID_H:
        return (option & PINYIN_FUZZY_F_H);
    case (PINYIN_ID_H << 16) | PINYIN_ID_F:
        return (option & PINYIN_FUZZY_H_F);
    case (PINYIN_ID_L << 16) | PINYIN_ID_R:
        return (option & PINYIN_FUZZY_L_R);
    case (PINYIN_ID_R << 16) | PINYIN_ID_L:
        return (option & PINYIN_FUZZY_R_L);
    case (PINYIN_ID_K << 16) | PINYIN_ID_G:
        return (option & PINYIN_FUZZY_K_G);
    case (PINYIN_ID_G << 16) | PINYIN_ID_K:
        return (option & PINYIN_FUZZY_G_K);
    default: return FALSE;
    }
}

static gboolean
pinyin_option_check_yun (guint option, gint id, gint fid)
{
    switch ((id << 16) | fid) {
    case (PINYIN_ID_AN << 16) | PINYIN_ID_ANG:
        return (option & PINYIN_FUZZY_AN_ANG);
    case (PINYIN_ID_ANG << 16) | PINYIN_ID_AN:
        return (option & PINYIN_FUZZY_ANG_AN);
    case (PINYIN_ID_EN << 16) | PINYIN_ID_ENG:
        return (option & PINYIN_FUZZY_EN_ENG);
    case (PINYIN_ID_ENG << 16) | PINYIN_ID_EN:
        return (option & PINYIN_FUZZY_ENG_EN);
    case (PINYIN_ID_IN << 16) | PINYIN_ID_ING:
        return (option & PINYIN_FUZZY_IN_ING);
    case (PINYIN_ID_ING << 16) | PINYIN_ID_IN:
        return (option & PINYIN_FUZZY_ING_IN);
    case (PINYIN_ID_UAN << 16) | PINYIN_ID_UANG:
        return (option & PINYIN_FUZZY_UAN_UANG);
    case (PINYIN_ID_UANG << 16) | PINYIN_ID_UAN:
        return (option & PINYIN_FUZZY_UANG_UAN);
    default: return FALSE;
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
    GString *cond;
    sqlite3_stmt *stmt;
    gint i;

    if (pinyin_len > pinyin->len - pinyin_begin)
        pinyin_len = pinyin->len - pinyin_begin;
    if (pinyin_len > 16)
        return FALSE;

    /* prepare sql */
    g_array_set_size (db->conditions, 1);
    g_array_index (db->conditions, GString *, 0) = _py_db_get_string (db);


    for (i = 0; i < pinyin_len; i++) {
        PinYin *p;
        gboolean fs1, fs2;
        p = g_array_index (pinyin, PinYin *, i + pinyin_begin);

        fs1 = pinyin_option_check_sheng (option, p->sheng_id, p->fsheng_id);
        fs2 = pinyin_option_check_sheng (option, p->sheng_id, p->fsheng_id_2);

        if (i > 0)
            _conditions_append_printf (db->conditions, 0, db->conditions->len, " AND ");

        if (fs1 || fs2) {
            if (i < DB_INDEX_SIZE) {
                if (fs1 && fs2 == 0) {
                    _conditions_double (db);
                    _conditions_append_printf (db->conditions,
                                               0, db->conditions->len  >> 1,
                                               "s%d=%d", i, p->sheng_id);
                    _conditions_append_printf (db->conditions,
                                               db->conditions->len >> 1, db->conditions->len,
                                               "s%d=%d", i, p->fsheng_id);
                }
                else if (fs1 == 0 && fs2) {
                    _conditions_double (db);
                    _conditions_append_printf (db->conditions,
                                               0, db->conditions->len  >> 1,
                                               "s%d=%d", i, p->sheng_id);
                    _conditions_append_printf (db->conditions,
                                               db->conditions->len >> 1, db->conditions->len,
                                               "s%d=%d", i, p->fsheng_id_2);
                }
                else {
                    gint len = db->conditions->len;
                    _conditions_triple (db);
                    _conditions_append_printf (db->conditions,
                                               0, len,
                                               "s%d=%d", i, p->sheng_id);
                    _conditions_append_printf (db->conditions,
                                               len, len << 1,
                                               "s%d=%d", i, p->fsheng_id);
                    _conditions_append_printf (db->conditions,
                                               len << 1, db->conditions->len,
                                               "s%d=%d", i, p->fsheng_id_2);
                }
            }
            else {
                if (fs1 && fs2 == 0) {
                    _conditions_append_printf (db->conditions, 0, db->conditions->len, "s%d IN (%d, %d)", i, p->sheng_id, p->fsheng_id);
                }
                else if (fs1 == 0 && fs2) {
                    _conditions_append_printf (db->conditions,
                                               0, db->conditions->len,
                                               "s%d IN (%d, %d)", i, p->sheng_id, p->fsheng_id_2);
                }
                else {
                    _conditions_append_printf (db->conditions,
                                               0, db->conditions->len,
                                               "s%d IN (%d, %d, %d)", i, p->sheng_id, p->fsheng_id, p->fsheng_id_2);
                }
            }
        }
        else {
            _conditions_append_printf (db->conditions, 0, db->conditions->len, "s%d=%d", i, p->sheng_id);
        }

        if (p->yun_id != PINYIN_ID_VOID) {
            if (pinyin_option_check_yun (option, p->yun_id, p->fyun_id)) {
                if (i < DB_INDEX_SIZE) {
                    _conditions_double (db);
                    _conditions_append_printf (db->conditions, 0, db->conditions->len  >> 1, " AND y%d=%d", i, p->yun_id);
                    _conditions_append_printf (db->conditions, db->conditions->len >> 1, db->conditions->len, " and y%d=%d", i, p->fyun_id);
                }
                else {
                    _conditions_append_printf (db->conditions, 0, db->conditions->len, " AND y%d IN (%d, %d)", i, p->yun_id, p->fyun_id);
                }
            }
            else {
                _conditions_append_printf (db->conditions, 0, db->conditions->len, " AND y%d=%d", i, p->yun_id);
            }
        }
    }

    g_string_printf (db->sql,
        "SELECT * FROM main.py_phrase_%d\n"
        "  WHERE\n", pinyin_len - 1);

    for (i = 0; i < db->conditions->len; i++) {
        cond = g_array_index (db->conditions, GString *, i);
        if (i == 0)
            g_string_append_printf (db->sql, "    (%s)\n", cond->str);
        else
            g_string_append_printf (db->sql, "    OR (%s)\n", cond->str);
        _py_db_put_string (db, cond);
    }

    g_array_set_size (db->conditions, 0);

    if (m > 0)
        g_string_append_printf (db->sql, "  ORDER BY freq DESC LIMIT %d", m);
    else
        g_string_append (db->sql, "  ORDER BY freq DESC");
#if 1
    if (pinyin_len == pinyin->len)
        g_debug ("sql =\n%s", db->sql->str);
#endif

    /* query database */
    if (sqlite3_prepare (db->db, db->sql->str, -1, &stmt, NULL) != SQLITE_OK) {
        g_debug ("parse sql failed!");
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
