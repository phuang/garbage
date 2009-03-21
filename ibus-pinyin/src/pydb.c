/* vim:set et sts=4: */
#include <locale.h>
#include <glib.h>
#include <sqlite3.h>
#include "pinyin.h"
#include "pydb.h"

typedef struct _PYDB PYDB;

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

#ifdef TEST

#include <sys/time.h>

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
