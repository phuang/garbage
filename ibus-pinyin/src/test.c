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
    gint j;
    gint c;

    if (*p < 'a' || *p > 'z')
       return NULL;

    c = *p - 'a';

    if (pinyin_table[c] == NULL)
       return NULL;

    if (len > 6)
        return NULL;

    if (len > 0) {
        if (pinyin_table[c][len] == NULL)
            return NULL;
        for (i = 0; pinyin_table[c][len][i].text != 0; i++) {
            if (strncmp (p, pinyin_table[c][len][i].text, len) == 0 &&
               ((pinyin_table[c][len][i].flags & option) || pinyin_table[c][len][i].flags == 0)) {
                   return &(pinyin_table[c][len][i]);
            }
        }
    }
    else {
        gint j;
        for (j = 6; j > 0; j --) {
            if (pinyin_table[c][j] == NULL)
                continue;
            for (i = 0; pinyin_table[c][j][i].text != 0; i++) {
                if (strncmp (p, pinyin_table[c][j][i].text, j) == 0 &&
                    ((pinyin_table[c][j][i].flags & option) || pinyin_table[c][j][i].flags == 0)) {
                        return &(pinyin_table[c][j][i]);
                }
            }
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
    gboolean is_rng;
    gint i;

    array = g_array_new (TRUE, FALSE, sizeof (const PinYin *));
    p = str;

    is_rng = FALSE;
    prev_py = NULL;

    for (; *p != '\0'; ) {

        if (is_rng && (*p == 'i' || *p == 'u' || *p == 'v')) {
            const PinYin *new_py;
            py = is_pinyin (p - 1, -1, option);
            if (py == NULL)
                break;
            new_py = is_pinyin (prev_py->text, prev_py->len - 1, option);
            if (new_py == NULL)
                break;
            g_array_index (array, const PinYin *, array->len - 1) = new_py;
            p --;
            prev_py = new_py;
            is_rng = FALSE;
        }
        else {
            py = is_pinyin (p, -1, option);
            if (py == NULL)
                break;
        }

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

                if ((p1 = is_pinyin(prev_py->text, prev_py->len -1, option)) == NULL) {
                    g_array_append_val (array, py);
                    break;
                }

                new_pinyin[0] = prev_py->text[prev_py->len - 1];
                strcpy(new_pinyin + 1, py->text);

                if ((p2 = is_pinyin (new_pinyin, py->len + 1, option)) == NULL) {
                    g_array_append_val (array, py);
                    break;
                }

                g_array_index (array, const PinYin *, array->len - 1) = p1;
                py = p2;
                p --;
                break;
            }
            default:
                break;
            }
        }

        g_array_append_val (array, py);
        p += py->len;

        switch (py->text[py->len - 1]) {
        case 'r':
        case 'n':
        case 'g':
            is_rng = TRUE;
            break;
        default:
            is_rng = FALSE;
        }

        prev_py = py;

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
    gint len;

    len = py_parse_pinyin (argv[1], &array, PINYIN_SIMPLE_PINYIN);

    gint i;
    for (i = 0; i < array->len; i++) {
        printf ("%s%s'", g_array_index (array, const PinYin *, i)->sheng, g_array_index (array, const PinYin *, i)->yun);
    }
    printf (" + %s\n", argv[1] + len);
}
