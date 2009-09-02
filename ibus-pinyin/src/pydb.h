/* vim:set et sts=4: */
#ifndef __PY_DB_H__
#define __PY_DB_H__

#include "pinyin.h"
#include "pyphrasearray.h"

typedef struct _PYDB PYDB;

PYDB            *py_db_new      ();
void             py_db_free     (PYDB   *db);
PYPhraseArray   *py_db_query    (PYDB   *db,
                                 GArray *pinyin,
                                 gint    m,
                                 guint   option);
#endif
