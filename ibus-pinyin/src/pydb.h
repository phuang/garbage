/* vim:set et sts=4: */
#ifndef __PYDB_H__
#define __PYDB_H__

#include "pinyin.h"

typedef struct _PYDB PYDB;
typedef struct _PYPhrase PYPhrase;

struct _PYPhrase {
    gchar *phrase;
    struct pinyin_t *pinyin;
    gint len;
};

#endif
