/* vim:set et sts=4: */
#include <string.h>
#include <stdlib.h>
#include <glib.h>
#include "Table.h"
#include "PinyinParser.h"

namespace PY {

static int
py_cmp (const void *p1, const void *p2)
{
    const gchar *str = (const gchar *) p1;
    const Pinyin *py = (const Pinyin *) p2;

    return strcmp (str, py->text);
}

static const Pinyin *
is_pinyin (const gchar *p,
           const gchar *end,
           gint         len,
           guint        option)
{
    gchar buf[7];
    const Pinyin *result;

    if (G_UNLIKELY (len > 6))
        return NULL;

    if (G_UNLIKELY (len > end - p))
        return NULL;

    if (G_LIKELY (len > 0)) {
        strncpy (buf, p, len);
        buf[len] = 0;
        result = (const Pinyin *) bsearch (buf, pinyin_table, PINYIN_TABLE_NR,
                                            sizeof (Pinyin), py_cmp);
        if (G_UNLIKELY (result == NULL))
            return NULL;
        if (G_LIKELY (result->flags == 0))
            return result;
        if(G_LIKELY (result->flags & option))
            return result;
        return NULL;
    }

    len = strnlen (p, 6);
    len = MIN (len, end - p);
    strncpy (buf, p, len);

    for (; len > 0; len --) {
        buf[len] = 0;
        result = (const Pinyin *) bsearch (buf, pinyin_table, PINYIN_TABLE_NR,
                                            sizeof (Pinyin), py_cmp);
        if (G_UNLIKELY (result && ((result->flags == 0) || (result->flags & option)))) {
            return result;
        }
    }

    return NULL;
}

static int
sp_cmp (const void *p1,
        const void *p2)
{
    const Pinyin **pys = (const Pinyin **) p1;
    const Pinyin **e = (const Pinyin **) p2;

    gint r;

    r = strcmp (pys[0]->text, e[0]->text);
    if (r == 0)
        r = strcmp (pys[1]->text, e[1]->text);
    return r;
}

static const Pinyin **
need_resplit(const Pinyin *p1,
             const Pinyin *p2)
{
    const Pinyin * pys[] = {p1, p2};

    return (const Pinyin **) bsearch (pys, special_table, SPECIAL_TABLE_NR,
                                        sizeof (special_table[0]), sp_cmp);
}

guint
PinyinParser::parse (const String  &pinyin, gint len, guint option, PinyinArray &result)
{

    const gchar *p;
    const gchar *end;
    const Pinyin *py;
    const Pinyin *prev_py;
    gchar prev_c;

    result.removeAll ();
    
    if (len < 0)
        len = pinyin.length ();

    p = pinyin;
    end = p + len;

    prev_py = NULL;

    prev_c = 0;
    for (; p < end; ) {
        switch (prev_c) {
        case 'r':
        case 'n':
        case 'g':
        case 'e':
            switch (*p) {
            case 'i':
            case 'u':
            case 'v':
            case 'a':
            case 'e':
            case 'o':
            case 'r':
                {
                    const Pinyin **pp;
                    const Pinyin *new_py1;
                    const Pinyin *new_py2;

                    py = is_pinyin (p, end, -1, option);

                    if ((new_py1 = is_pinyin (prev_py->text,
                                              prev_py->text + prev_py->len,
                                              prev_py->len - 1,
                                              option)) != NULL) {
                        new_py2 = is_pinyin (p -1, end, -1, option);

                        if (((new_py2 != NULL) && (new_py2->len > 1 )) &&
                            (py == NULL || new_py2->len > py->len + 1)) {
                            result[result.length () - 1] = new_py1;
                            py = new_py2;
                            p --;
                            break;
                        }
                    }

                    if ( py == NULL) {
                        break;
                    }

                    pp = need_resplit (prev_py, py);
                    if (pp != NULL) {
                        result[result.length () - 1] = pp[2];
                        py = pp[3];
                        p --;
                        break;
                    }
                }
            default:
                py = is_pinyin (p, end, -1, option);
                break;
            }
            break;
        default:
            py = is_pinyin (p, end, -1, option);
            break;
        }

        if (py == NULL)
            break;

        result << py;
        p += py->len;
        prev_c = py->text[py->len - 1];
        prev_py = py;

        if (*p == '\'') {
            prev_c = '\'';
            p++;
        }
    }

    if (G_UNLIKELY (p == (const gchar *)pinyin)) {
        return 0;
    }

    if (G_UNLIKELY (*(p - 1) == '\''))
        p --;

    return p - (const gchar *)pinyin;
}

};


#ifdef TEST
#include <glib/gprintf.h>
int main(int argc, char **argv)
{
    gint len;
    GArray *array;
    Pinyin **p;
    gchar *str;

    str = "qinaide";

    if (argc > 1)
        str = argv[1];

    array = g_array_new (TRUE, TRUE, sizeof (Pinyin *));

    len = py_parse_pinyin (str, -1, 0xffffffff, array);

    if (len) {
        p = (Pinyin **) array->data;
        while (*p) {
            g_printf ("%s'", (*p)->text);
            p ++;
        }
    }
    g_printf ("%s\n", str + len);

    return 0;
}
#endif
