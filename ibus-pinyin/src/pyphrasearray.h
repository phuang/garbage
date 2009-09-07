/* vim:set et sts=4: */
#ifndef __PY_PHRASE_ARRAY_H__
#define __PY_PHRASE_ARRAY_H__

#include <glib.h>

#define MAX_UTF8_LEN 6
#define MAX_PHRASE_LEN 16

typedef struct _PYPhrase PYPhrase;
struct _PYPhrase {
    gchar phrase[(MAX_PHRASE_LEN + 1) * MAX_UTF8_LEN];
    gint freq;
    gint pinyin_id[MAX_PHRASE_LEN][2];
    gint len;
};

typedef GArray PYPhraseArray;

PYPhraseArray   *py_phrase_array_new    ();
void             py_phrase_array_free    (PYPhraseArray *array);
PYPhrase        *py_phrase_array_index  (PYPhraseArray  *array,
                                         gint            i);
PYPhrase        *py_phrase_array_append (PYPhraseArray  *array);
void             py_phrase_array_remove_all
                                        (PYPhraseArray  *array);

#define py_phrase_array_len(a) ((a)->len)

#endif
