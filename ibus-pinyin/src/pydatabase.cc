/* vim:set et sts=4: */
#include <string.h>
#include <glib.h>
#include <sqlite3.h>
#include <stdio.h>
#include <stdarg.h>
#include "pytypes.h"
#include "pydatabase.h"

using namespace PY;

#define DB_CACHE_SIZE "5000"
#define DB_INDEX_SIZE (3)

Database::Database (void)
    : m_db (NULL),
      m_sql (1024),
      m_conditions (32),
      m_strings (32)
{
    gchar *sql;
    const gchar *userdb;
    gchar *errmsg;

    sqlite3_initialize ();

    if (sqlite3_open_v2 ("py.db", &m_db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL) != SQLITE_OK) {
        goto _failed;
    }

    userdb = "/home/phuang/.cache/ibus/ibus-pinyin/user.db";
    sql = g_strdup_printf ("ATTACH DATABASE \"%s\" AS userdb;", userdb);
    if (sqlite3_exec (m_db, sql, NULL, NULL, &errmsg) != SQLITE_OK) {
        g_debug ("%s", errmsg);
        sqlite3_free (errmsg);
        goto _failed;
    }
    g_free (sql);

    if (sqlite3_exec (m_db, "PRAGMA cache_size=" DB_CACHE_SIZE, NULL, NULL, &errmsg) != SQLITE_OK) {
        g_debug ("%s", errmsg);
        sqlite3_free (errmsg);
        goto _failed;
    }
    return;

_failed:
    if (m_db) {
        sqlite3_close (m_db);
        m_db = NULL;
    }
}

Database::~Database (void)
{
    for (guint i = 0; i < m_strings.length (); i++) {
        delete m_strings[i];
    }

    if (m_db) {
        sqlite3_close (m_db);
        m_db = NULL;
    }
}

gboolean
Database::query (const PinYinArray &pinyin,
                 guint              m,
                 guint              option,
                 PhraseArray       &result)
{
    gint len;
    gint i;

    len = MIN (pinyin.length (), MAX_PHRASE_LEN);

    for (i = len; i > 0; i--) {
        if (m < 0) {
            if (!queryInternal (pinyin, 0, i, -1, option, result))
                return FALSE;
        }
        else {
            if (!queryInternal (pinyin, 0, i, m - result.length (), option, result))
                return FALSE;
            if (result.length () >= m)
                break;
        }
    }
    return TRUE;
}



static void
_conditions_append_vprintf (Array<String *> &array,
                            gint             begin,
                            gint             end,
                            const gchar     *fmt,
                            va_list          args)
{
    gchar str[64];
    g_vsnprintf (str, sizeof(str), fmt, args);

    for (gint i = begin; i < end; i++) {
        (*array[i]) << str;
    }
}

static void
_conditions_append_printf (Array<String *> &array,
                           gint             begin,
                           gint             end,
                           const gchar     *fmt,
                           ...)
{
    va_list args;
    va_start (args, fmt);
    _conditions_append_vprintf (array, begin, end, fmt, args);
    va_end (args);
}

#define CONDITION_INIT_SIZE (256)

void
Database::conditionsDouble (void)
{
    gint i, len;

    len = m_conditions.length ();

    for (i = 0; i < len; i++) {
        String *new_str;
        new_str = string (len + i);
        *new_str = *m_conditions[i];
        m_conditions << new_str;
    }
}

void
Database::conditionsTriple (void)
{
    gint i, len;

    len = m_conditions.length ();

    for (i = 0; i < len; i++) {
        String *new_str;
        new_str = string ((i << 1) + len);
        *new_str = *m_conditions[i];
        m_conditions << new_str;
        new_str = string ((i << 1) + len + 1);
        *new_str = *m_conditions[i];
        m_conditions << new_str;
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
Database::queryInternal (const PinYinArray &pinyin,
                         guint              pinyin_begin,
                         guint              pinyin_len,
                         gint               m,
                         guint              option,
                         PhraseArray       &result)
{
    if (G_UNLIKELY (pinyin_begin > pinyin.length ()))
        pinyin_begin = pinyin.length ();

    if (G_UNLIKELY (pinyin_len > pinyin.length () - pinyin_begin))
        pinyin_len = pinyin.length () - pinyin_begin;
    if (G_UNLIKELY (pinyin_len > 16))
        return FALSE;

    /* prepare sql */
    m_conditions.setSize (1);
    m_conditions[0] = this->string (0);

    for (guint i = 0; i < pinyin_len; i++) {
        const PinYin *p;
        gboolean fs1, fs2;
        p = pinyin[i + pinyin_begin];

        fs1 = pinyin_option_check_sheng (option, p->sheng_id, p->fsheng_id);
        fs2 = pinyin_option_check_sheng (option, p->sheng_id, p->fsheng_id_2);

        if (G_LIKELY (i > 0))
            _conditions_append_printf (m_conditions,
                                       0, m_conditions.length (),
                                       " AND ");

        if (fs1 || fs2) {
            if (G_LIKELY (i < DB_INDEX_SIZE)) {
                if (fs1 && fs2 == 0) {
                    conditionsDouble ();
                    _conditions_append_printf (m_conditions,
                                               0, m_conditions.length ()  >> 1,
                                               "s%d=%d", i, p->sheng_id);
                    _conditions_append_printf (m_conditions,
                                               m_conditions.length () >> 1, m_conditions.length (),
                                               "s%d=%d", i, p->fsheng_id);
                }
                else if (fs1 == 0 && fs2) {
                    conditionsDouble ();
                    _conditions_append_printf (m_conditions,
                                               0, m_conditions.length ()  >> 1,
                                               "s%d=%d", i, p->sheng_id);
                    _conditions_append_printf (m_conditions,
                                               m_conditions.length () >> 1, m_conditions.length (),
                                               "s%d=%d", i, p->fsheng_id_2);
                }
                else {
                    gint len = m_conditions.length ();
                    conditionsTriple ();
                    _conditions_append_printf (m_conditions,
                                               0, len,
                                               "s%d=%d", i, p->sheng_id);
                    _conditions_append_printf (m_conditions,
                                               len, len << 1,
                                               "s%d=%d", i, p->fsheng_id);
                    _conditions_append_printf (m_conditions,
                                               len << 1, m_conditions.length (),
                                               "s%d=%d", i, p->fsheng_id_2);
                }
            }
            else {
                if (fs1 && fs2 == 0) {
                    _conditions_append_printf (m_conditions,
                                               0, m_conditions.length (),
                                               "s%d IN (%d, %d)", i, p->sheng_id, p->fsheng_id);
                }
                else if (fs1 == 0 && fs2) {
                    _conditions_append_printf (m_conditions,
                                               0, m_conditions.length (),
                                               "s%d IN (%d, %d)", i, p->sheng_id, p->fsheng_id_2);
                }
                else {
                    _conditions_append_printf (m_conditions,
                                               0, m_conditions.length (),
                                               "s%d IN (%d, %d, %d)", i, p->sheng_id, p->fsheng_id, p->fsheng_id_2);
                }
            }
        }
        else {
            _conditions_append_printf (m_conditions,
                                       0, m_conditions.length (),
                                       "s%d=%d", i, p->sheng_id);
        }

        if (p->yun_id != PINYIN_ID_VOID) {
            if (pinyin_option_check_yun (option, p->yun_id, p->fyun_id)) {
                if (G_LIKELY (i < DB_INDEX_SIZE)) {
                    conditionsDouble ();
                    _conditions_append_printf (m_conditions,
                                               0, m_conditions.length ()  >> 1,
                                               " AND y%d=%d", i, p->yun_id);
                    _conditions_append_printf (m_conditions,
                                               m_conditions.length () >> 1, m_conditions.length (),
                                               " and y%d=%d", i, p->fyun_id);
                }
                else {
                    _conditions_append_printf (m_conditions,
                                               0, m_conditions.length (),
                                               " AND y%d IN (%d, %d)", i, p->yun_id, p->fyun_id);
                }
            }
            else {
                _conditions_append_printf (m_conditions,
                                           0, m_conditions.length (),
                                           " AND y%d=%d", i, p->yun_id);
            }
        }
    }

    m_sql = "SELECT * FROM main.py_phrase_";
    m_sql << pinyin_len - 1 << "\n"
             "  WHERE\n";

    for (guint i = 0; i < m_conditions.length (); i++) {
        if (i == 0)
            m_sql << "    (" << (*m_conditions[i]) << ")\n";
        else
            m_sql << "    OR (" << (*m_conditions[i]) << ")\n";
    }
    m_conditions.setSize (0);

    if (m > 0)
        m_sql << "  ORDER BY freq DESC LIMIT " << m;
    else
        m_sql << "  ORDER BY freq DESC";
#if 0
    g_debug ("sql =\n%s", db->sql->str);
#endif

    /* query database */
    sqlite3_stmt *stmt;
    if (sqlite3_prepare (m_db,
                         (const gchar *) m_sql,
                         -1,
                         &stmt,
                         NULL) != SQLITE_OK) {
        g_debug ("parse sql failed!\n %s", (const gchar *)m_sql);
        return FALSE;
    }

    while (sqlite3_step (stmt) == SQLITE_ROW) {
        result.setSize (result.length () + 1);
        Phrase &p = result[result.length() - 1];

        strcpy (p.phrase, (gchar *) sqlite3_column_text (stmt, 0));
        p.freq = sqlite3_column_int (stmt, 1);
        p.len = pinyin_len;

        for (guint i = 0; i < pinyin_len; i++) {
            p.pinyin_id[i][0] = sqlite3_column_int (stmt, (i << 1) + 2);
            p.pinyin_id[i][1] = sqlite3_column_int (stmt, (i << 1) + 3);
        }
    }

    sqlite3_finalize (stmt);
    return TRUE;
}

