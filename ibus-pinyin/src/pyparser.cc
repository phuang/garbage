/* vim:set et sts=4: */
#include <string.h>
#include <stdlib.h>
#include <glib.h>
#include "pytable.h"
#include "pyparser.h"

namespace PY {

static int
py_cmp (const void *p1, const void *p2)
{
    const gchar *str = (const gchar *) p1;
    const PinYin *py = (const PinYin *) p2;

    return strcmp (str, py->text);
}

static const PinYin *
is_pinyin (const gchar *p,
           const gchar *end,
           gint         len,
           guint        option)
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
        result = (const PinYin *) bsearch (buf, pinyin_table, PINYIN_TABLE_NR,
                                            sizeof (PinYin), py_cmp);
        if (result &&
            result->flags != 0 &&
            ((result->flags & option) == 0))
            return NULL;
        return result;
    }

    len = strnlen (p, 6);
    len = MIN (len, end - p);
    strncpy (buf, p, len);

    for (; len > 0; len --) {
        buf[len] = 0;
        result = (const PinYin *) bsearch (buf, pinyin_table, PINYIN_TABLE_NR,
                                            sizeof (PinYin), py_cmp);
        if (result && ((result->flags == 0) || (result->flags & option))) {
            return result;
        }
    }

    return NULL;
}

static int
sp_cmp (const void *p1,
        const void *p2)
{
    const PinYin **pys = (const PinYin **) p1;
    const PinYin **e = (const PinYin **) p2;

    gint r;

    r = strcmp (pys[0]->text, e[0]->text);
    if (r == 0)
        r = strcmp (pys[1]->text, e[1]->text);
    return r;
}

static const PinYin **
need_resplit(const PinYin *p1,
             const PinYin *p2)
{
    const PinYin * pys[] = {p1, p2};

    return (const PinYin **) bsearch (pys, special_table, SPECIAL_TABLE_NR,
                                        sizeof (special_table[0]), sp_cmp);
}

guint
PinYinParser::parse (const String  &pinyin, gint len, PinYinArray &result)
{

    const gchar *p;
    const gchar *end;
    const PinYin *py;
    const PinYin *prev_py;
    gboolean is_rng;

    result.removeAll ();
    
    if (len < 0)
        len = pinyin.length ();

    p = pinyin;
    end = p + len;

    is_rng = FALSE;
    prev_py = NULL;


    for (; p < end; ) {

        if (is_rng) {
            switch (*p) {
            case 'i':
            case 'u':
            case 'v':
            case 'a':
            case 'e':
            case 'o':
                {
                    const PinYin **pp;
                    const PinYin *new_py1;
                    const PinYin *new_py2;

                    py = is_pinyin (p, end, -1, m_option);

                    if ((new_py1 = is_pinyin (prev_py->text,
                                              prev_py->text + prev_py->len,
                                              prev_py->len - 1,
                                              m_option)) != NULL) {
                        new_py2 = is_pinyin (p -1, end, -1, m_option);

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
                py = is_pinyin (p, end, -1, m_option);
                break;
            }
        }
        else {
            py = is_pinyin (p, end, -1, m_option);
        }

        if (py == NULL)
            break;
        result << py;
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

    if (p == (const gchar *)pinyin) {
        return 0;
    }

    if (*(p - 1) == '\'')
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
    PinYin **p;
    gchar *str;

    str = "qinaide";

    if (argc > 1)
        str = argv[1];

    array = g_array_new (TRUE, TRUE, sizeof (PinYin *));

    len = py_parse_pinyin (str, -1, 0xffffffff, array);

    if (len) {
        p = (PinYin **) array->data;
        while (*p) {
            g_printf ("%s'", (*p)->text);
            p ++;
        }
    }
    g_printf ("%s\n", str + len);

    return 0;
}
#endif
