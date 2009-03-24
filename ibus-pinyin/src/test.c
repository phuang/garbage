/* vim:set et sts=4: */
#include <glib.h>
#include <string.h>
#include <stdio.h>
#include "test.h"

static const gchar *
is_pinyin (const gchar *p,
           gint         len)
{
    gint i;
    gint c;

    if (*p < 'a' || *p > 'z')
       return NULL;
   
    c = *p - 'a';

    if (pinyin_table[c] == NULL)
       return NULL;

    if (len > 6 || len < 0)
        return NULL;
   
    if (pinyin_table[c][len] == NULL)
        return NULL;

    for (i = 0; pinyin_table[c][len][i] != NULL; i++) {
        if (strncmp (p, pinyin_table[c][len][i], len) == 0) {
               return pinyin_table[c][len][i];
        }
    }

    return NULL;
}

gint
py_parse_pinyin (const gchar  *str,
                 GArray      **result)
{
    const gchar *p;
    GArray *array;
    const gchar *py;
    const gchar *prev_py;
    gint prev_py_len;
    gboolean is_rng;
    gint i;

    array = g_array_new (TRUE, FALSE, sizeof (gchar *));

    is_rng = FALSE;
    prev_py = NULL;
    
    for (p = str; *p != 0; ) {
        for (i = 6; i > 0; i --) {
            py = is_pinyin (p, i);
            if (py)
                break;            
        }
        if (!py)
            break;

        if (is_rng) {
            switch (py[0]) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            {
                gchar new_pinyin[7];
                const gchar *p1;
                const gchar *p2;
                
                if ((p1 = is_pinyin(prev_py, prev_py_len -1)) == NULL) {
                    g_array_append_val (array, py);
                    break;
                }
                
                new_pinyin[0] = prev_py[prev_py_len - 1];
                strcpy(new_pinyin + 1, py);
                
                if ((p2 = is_pinyin (new_pinyin, i + 1)) == NULL) {
                    g_array_append_val (array, py);
                    break;
                }
                
                g_array_index (array, const gchar *, array->len - 1) = p1;
                py = p2;
                break;
            }
            default:
                break;
            }
        }
        
        g_array_append_val (array, py);
        p += i;
        
        switch (py[i - 1]) {
        case 'r':
        case 'n':
        case 'g':
            is_rng = TRUE;
            break;
        default:
            is_rng = FALSE;
        }

        prev_py = py;
        prev_py_len = i;
    }

    *result = array;
    return p - str;
}


int main (int argc, char **argv)
{
    GArray *array;
    py_parse_pinyin (argv[1], &array);

    gint i;
    for (i = 0; i < array->len; i++) {
        printf ("%s'", g_array_index (array, gchar *, i));
    }
    printf ("\n");
}
