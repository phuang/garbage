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
    gint ref;
};

typedef struct _PYPhraseArray PYPhraseArray;
struct _PYPhraseArray {
    GPtrArray *array;
    gint ref;
};

PYPhrase        *py_phrase_new          ();
PYPhrase        *py_phrase_ref          (PYPhrase       *phrase);
void             py_phrase_unref        (PYPhrase       *phrase);

PYPhraseArray   *py_phrase_array_new    ();
PYPhraseArray   *py_phrase_array_ref    (PYPhraseArray  *array);
void             py_phrase_array_unref  (PYPhraseArray  *array);
PYPhrase        *py_phrase_array_index  (PYPhraseArray  *array,
                                         gint            i);
PYPhrase        *py_phrase_array_new_phrase
                                        (PYPhraseArray  *array);
PYPhraseArray   *py_phrase_array_append (PYPhraseArray  *array,
                                         PYPhrase       *phrase);
PYPhraseArray   *py_phrase_array_append_array
                                        (PYPhraseArray  *array1,
                                         PYPhraseArray  *array2);

#define py_phrase_array_len(a) ((a)->array->len)

#endif