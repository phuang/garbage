/* vim:set et sts=4: */
#include <string.h>
#include <stdlib.h>
#include <glib.h>
#include "Table.h"
#include "PinyinParser.h"

namespace PY {

static const gint double_pinyin_ms_sheng[] = {
    PINYIN_ID_VOID,             // A
    PINYIN_ID_B,                // B
    PINYIN_ID_C,                // C
    PINYIN_ID_D,                // D
    PINYIN_ID_VOID,             // E
    PINYIN_ID_F,                // F
    PINYIN_ID_G,                // G
    PINYIN_ID_H,                // H
    PINYIN_ID_CH,               // I
    PINYIN_ID_J,                // J
    PINYIN_ID_K,                // K
    PINYIN_ID_L,                // L
    PINYIN_ID_M,                // M
    PINYIN_ID_N,                // N
    PINYIN_ID_VOID,             // O
    PINYIN_ID_P,                // P
    PINYIN_ID_Q,                // Q
    PINYIN_ID_R,                // R
    PINYIN_ID_S,                // S
    PINYIN_ID_T,                // T
    PINYIN_ID_SH,               // U
    PINYIN_ID_ZH,               // V
    PINYIN_ID_W,                // W
    PINYIN_ID_X,                // X
    PINYIN_ID_Y,                // Y
    PINYIN_ID_Z,                // Z
    PINYIN_ID_VOID,             // ;
};
static const gint double_pinyin_ms_yun[][2] = {
    { PINYIN_ID_A, PINYIN_ID_VOID },        // A
    { PINYIN_ID_A, PINYIN_ID_VOID },        // B
    { PINYIN_ID_A, PINYIN_ID_VOID },        // C
    { PINYIN_ID_A, PINYIN_ID_VOID },        // D
    { PINYIN_ID_A, PINYIN_ID_VOID },        // E
    { PINYIN_ID_A, PINYIN_ID_VOID },        // F
    { PINYIN_ID_A, PINYIN_ID_VOID },        // G
    { PINYIN_ID_A, PINYIN_ID_VOID },        // H
    { PINYIN_ID_A, PINYIN_ID_VOID },        // I
    { PINYIN_ID_A, PINYIN_ID_VOID },        // J
    { PINYIN_ID_A, PINYIN_ID_VOID },        // K
    { PINYIN_ID_A, PINYIN_ID_VOID },        // L
    { PINYIN_ID_A, PINYIN_ID_VOID },        // M
    { PINYIN_ID_A, PINYIN_ID_VOID },        // N
    { PINYIN_ID_A, PINYIN_ID_VOID },        // O
    { PINYIN_ID_A, PINYIN_ID_VOID },        // P
    { PINYIN_ID_A, PINYIN_ID_VOID },        // Q
    { PINYIN_ID_A, PINYIN_ID_VOID },        // R
    { PINYIN_ID_A, PINYIN_ID_VOID },        // S
    { PINYIN_ID_A, PINYIN_ID_VOID },        // T
    { PINYIN_ID_A, PINYIN_ID_VOID },        // Y
    { PINYIN_ID_A, PINYIN_ID_VOID },        // V
    { PINYIN_ID_A, PINYIN_ID_VOID },        // W
    { PINYIN_ID_A, PINYIN_ID_VOID },        // X
    { PINYIN_ID_A, PINYIN_ID_VOID },        // W
    { PINYIN_ID_A, PINYIN_ID_VOID },        // Z
    { PINYIN_ID_A, PINYIN_ID_VOID },        // ;
};

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

    return ((pys[0] - e[0]) << 16) + (pys[1] - e[1]);
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
PinyinParser::parse (const String   &pinyin,
                     gint            len,
                     guint           option,
                     PinyinArray    &result,
                     guint           max)
{

    const gchar *p;
    const gchar *end;
    const Pinyin *py;
    const Pinyin *prev_py;
    gchar prev_c;

    result.removeAll ();

    if (G_UNLIKELY (len < 0))
        len = pinyin.length ();

    p = pinyin;
    end = p + len;

    prev_py = NULL;

    prev_c = 0;
    for (; p < end && result.length () < max; ) {
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

                    if ( py == NULL)
                        break;

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

        if (G_UNLIKELY (py == NULL))
            break;

        result << py;
        p += py->len;
        prev_c = py->text[py->len - 1];
        prev_py = py;

        if (G_UNLIKELY (*p == '\'')) {
            prev_c = '\'';
            p++;
        }
    }

    if (G_UNLIKELY (p == (const gchar *)pinyin))
        return 0;
#if 0
    if (G_UNLIKELY (*(p - 1) == '\''))
        p --;
#endif
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
