/* vim:set et sts=4: */
#include <glib.h>
#include <string.h>
#include <stdio.h>
#include "test.h"

static const PinYin *
is_pinyin (const gchar *p,
           gint         len,
           gint         option)
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

    for (i = 0; pinyin_table[c][len][i].text != 0; i++) {
        if (strncmp (p, pinyin_table[c][len][i].text, len) == 0 &&
           ((pinyin_table[c][len][i].flags & option) || pinyin_table[c][len][i].flags == 0)) {
               return &(pinyin_table[c][len][i]);
        }
    }

    return NULL;
}

gint
py_parse_pinyin (const gchar  *str,
                 GArray      **result,
                 gint          option)
{
    const gchar *p;
    GArray *array;
    const PinYin *py;
    const PinYin *prev_py;
    gint prev_py_len;
    gboolean is_rng;
    gint i;

    array = g_array_new (TRUE, FALSE, sizeof (const PinYin *));
    p = str;

    is_rng = FALSE;
    prev_py = NULL;

    for (; *p != 0; ) {
        for (i = 6; i > 0; i --) {
            py = is_pinyin (p, i, option);
            if (py)
                break;            
        }
        if (!py)
            break;

        if (is_rng) {
            switch (py->text[0]) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            {
                gchar new_pinyin[7];
                const PinYin *p1;
                const PinYin *p2;
                
                if ((p1 = is_pinyin(prev_py->text, prev_py_len -1, option)) == NULL) {
                    g_array_append_val (array, py);
                    break;
                }
                
                new_pinyin[0] = prev_py->text[prev_py_len - 1];
                strcpy(new_pinyin + 1, py->text);
                
                if ((p2 = is_pinyin (new_pinyin, i + 1, option)) == NULL) {
                    g_array_append_val (array, py);
                    break;
                }
                
                g_array_index (array, const PinYin *, array->len - 1) = p1;
                py = p2;
                break;
            }
            default:
                break;
            }
        }
        
        g_array_append_val (array, py);
        p += i;
        
        switch (py->text[i - 1]) {
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

        if (*p == '\'') {
            p++;
            is_rng = FALSE;
        }
    }

    *result = array;
    return p - str;
}


int main (int argc, char **argv)
{
    GArray *array;
    py_parse_pinyin (argv[1], &array, PINYIN_SIMPLE_PINYIN);

    gint i;
    for (i = 0; i < array->len; i++) {
        printf ("%s%s'", g_array_index (array, const PinYin *, i)->sheng, g_array_index (array, const PinYin *, i)->yun);
    }
    printf ("\n");
}
