/* vim:set et sts=4: */
#ifndef __PYDB_H__
#define __PYDB_H__

#include "pinyin.h"

typedef struct _PYDB PYDB;
typedef struct _PYPhrase PYPhrase;

struct _PYPhrase {
    gchar *phrase;
    gint freq;
    gint pinyin_id[16][2];
    gint len;
};

PYDB    *py_db_new      ();
void     py_db_free     (PYDB   *db);
GArray  *py_db_query    (PYDB   *db,
                         GArray *pinyin,
                         gint    m);
void     py_db_query_result_free
                        (GArray *result);
#endif
