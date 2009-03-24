/* vim:set et sts=4: */
#define _GNU_SOURCE
#include <string.h>
#include <stdlib.h>
#include <glib.h>
#include "pytable.h"
#include "pyparser.h"

static int
py_cmp (const void *p1, const void *p2)
{
    const gchar *str = (const gchar *) p1;
    const PinYin *py = (PinYin *) p2;

    return strcmp (str, py->text);
}

static const PinYin *
is_pinyin (const gchar *p,
           const gchar *end,
           gint         len,
           gint         option)
{
    gchar buf[7];
    const PinYin *result;

    if (len > 6)
        return NULL;

    if (len > end - p)
        return NULL;

    if (len > 0) {
        strncpy (buf, p, len);
        buf[len] = 0;
        result = (const PinYin *) bsearch (buf, pinyin_table, PINYIN_TABLE_NR, sizeof (PinYin), py_cmp);
        if (result && result->flags != 0 && (result->flags & option == 0))
            return NULL;
        return result;
    }
    
    len = strnlen (p, 6);
    len = MIN (len, end - p);
    strncpy (buf, p, len);
    for (; len > 0; len --) {
        buf[len] = 0;
        result = (const PinYin *) bsearch (buf, pinyin_table, PINYIN_TABLE_NR, sizeof (PinYin), py_cmp);
        if (result && ((result->flags == 0) || (result->flags & option))) {
            return result;
        }
    }
    return NULL;
}

gint
py_parse_pinyin (const gchar  *str,
                 gint          len,
                 gint          option,
                 GArray      **result)
{
    const gchar *p;
    const gchar *end;
    GArray *array;
    const PinYin *py;
    const PinYin *prev_py;
    gboolean is_rng;

    if (len < 0)
        len = strlen (str);
    
    array = g_array_sized_new (TRUE, FALSE, sizeof (const PinYin *), len >> 1);
    p = str;
    end = str + len;

    is_rng = FALSE;
    prev_py = NULL;


    for (; p < end; ) {

        if (is_rng && (*p == 'i' || *p == 'u' || *p == 'v')) {
            const PinYin *new_py;
            py = is_pinyin (p - 1, end, -1, option);
            if (py == NULL)
                break;
            new_py = is_pinyin (prev_py->text, end, prev_py->len - 1, option);
            if (new_py == NULL)
                break;
            g_array_index (array, const PinYin *, array->len - 1) = new_py;
            p --;
            prev_py = new_py;
            is_rng = FALSE;
        }
        else {
            py = is_pinyin (p, end, -1, option);
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

                if ((p1 = is_pinyin(prev_py->text, prev_py->text + prev_py->len - 1, prev_py->len -1, option)) == NULL) {
                    g_array_append_val (array, py);
                    break;
                }

                new_pinyin[0] = prev_py->text[prev_py->len - 1];
                strcpy(new_pinyin + 1, py->text);

                if ((p2 = is_pinyin (new_pinyin, new_pinyin + py->len + 1, py->len + 1, option)) == NULL) {
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
    
    if (p == str) {
        g_array_free (array, TRUE);
        *result = NULL;
        return 0;
    }

    if (*(p - 1) == '\'')
        p --;

    *result = array;
    return p - str;
}


#ifdef TEST
#include <glib/gprintf.h>
int main(int argc, char **argv)
{
    gint len;
    GArray *array;
    PinYin **p;

    len = py_parse_pinyin ("qinaide", -1, 0, &array);

    if (len) {
        
        p = (PinYin **) array->data;
        while (*p) {
            g_printf ("%s'", (*p)->text);
            p ++;
        }
    }
    g_printf ("\n");

    return 0;
}
#endif
