/* vim:set et sts=4: */
#ifndef __PY_PHRASE_ARRAY_H__
#define __PY_PHRASE_ARRAY_H__

#include <glib.h>
#include "pyarray.h"

namespace PY {

#define MAX_UTF8_LEN 6
#define MAX_PHRASE_LEN 16

typedef struct _Phrase Phrase;
struct _Phrase {
    gchar phrase[(MAX_PHRASE_LEN + 1) * MAX_UTF8_LEN];
    gint freq;
    gint pinyin_id[MAX_PHRASE_LEN][2];
    gint len;
};


typedef Array<Phrase> PhraseArray;

};

#endif
