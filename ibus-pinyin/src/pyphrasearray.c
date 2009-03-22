#include "pyphrasearray.h"


PYPhrase *
py_phrase_new ()
{
	PYPhrase *p;
	p = g_slice_new0 (PYPhrase);
	p->ref = 1;
	return p;
}

PYPhrase *
py_phrase_ref (PYPhrase *phrase)
{
	phrase->ref ++;
	return phrase;
}

void
py_phrase_unref (PYPhrase *phrase)
{
	phrase->ref --;

	if (phrase->ref == 0) {
		g_slice_free (PYPhrase , phrase);
	}
}

PYPhraseArray *
py_phrase_array_new ()
{
	PYPhraseArray *p;
	p = g_slice_new0 (PYPhraseArray);
	p->array = g_ptr_array_sized_new (32);
	p->ref = 1;
	return p;
}

PYPhraseArray*
py_phrase_array_ref (PYPhraseArray  *array)
{
	array->ref ++;
	return array;
}

void
py_phrase_array_unref (PYPhraseArray *array)
{
	array->ref --;

	if (array->ref == 0) {
		g_ptr_array_foreach (array->array, (GFunc) py_phrase_unref, NULL);
		g_ptr_array_free (array->array, TRUE);
		g_slice_free (PYPhraseArray, array);
	}
}

PYPhrase *
py_phrase_array_index (PYPhraseArray *array,
					   gint           i)
{
	return (PYPhrase *) g_ptr_array_index (array->array, i);
}

PYPhraseArray *
py_phrase_array_append (PYPhraseArray *array,
                        PYPhrase      *phrase)
{
	g_ptr_array_add (array->array, py_phrase_ref (phrase));
	return array;
}


PYPhraseArray *
py_phrase_array_append_array (PYPhraseArray  *array1,
						      PYPhraseArray  *array2)
{
	gint i;

	for (i = 0; i < array2->array->len; i++) {
		g_ptr_array_add (array1->array,
			py_phrase_ref ((PYPhrase *) g_ptr_array_index (array2->array, i)));
	}
	return array1;
}
