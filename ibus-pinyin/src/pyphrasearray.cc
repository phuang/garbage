#include "pyphrasearray.h"


PYPhraseArray *
py_phrase_array_new ()
{
	return g_array_sized_new (FALSE, FALSE, sizeof (PYPhrase), 32);
}

void
py_phrase_array_free (PYPhraseArray *array)
{
	g_array_free (array, TRUE);
}

PYPhrase *
py_phrase_array_index (PYPhraseArray *array,
					   gint           i)
{
	return & (g_array_index (array, PYPhrase, i));
}

PYPhrase *
py_phrase_array_append (PYPhraseArray *array)
{
    g_array_set_size (array, array->len + 1);
    return &(g_array_index (array, PYPhrase, array->len - 1));
}

void
py_phrase_array_remove_all (PYPhraseArray *array)
{
    g_array_set_size (array, 0);
}
