/* vim:set et sts=4: */
#include <glib.h>
#include "pinyin.h"
#include "pyparser.h"
#include "pyscanner.h"

struct _PYParser {
    yyscan_t scanner;
};


PYParser *
py_parser_new (guint option)
{
    PYParser *parser;

    parser = g_slice_new (PYParser);
    yylex_init_extra (option, &(parser->scanner));

    return parser;
}

void
py_parser_destroy  (PYParser *parser)
{
    yylex_destroy (parser->scanner);
    g_slice_free (PYParser, parser);
}

extern int yyparse (gint *skip, GArray **array, void *scanner);

gint
py_parser_parse (PYParser    *parser,
                 const gchar *str,
                 gint         len,
                 GArray     **array)
{
    YY_BUFFER_STATE b;
    GArray *result;
    gchar *buf;
    gint retval;

    if (len < 0)
        len = strlen (str);

    buf = g_strndup (str, len);
    g_strreverse (buf);

    b = yy_scan_bytes (buf, len, parser->scanner);
    g_free (buf);

    result = NULL;
    retval = 0;
    if (yyparse (&retval, &result, parser->scanner) != 0) {
        result = NULL;
        retval = 0;
    }

    *array = result;
    yy_delete_buffer (b, parser->scanner);

    return retval;
}

void
py_parser_free_result (GArray *result)
{
    struct pinyin_t **p;

    p = (struct pinyin_t **) result->data;

    while (*p != NULL) {
        pinyin_free (*(p++));
    }

    g_array_free (result, TRUE);
}

void
py_parser_set_option (PYParser *parser,
                      guint     option)
{
    yyset_extra (option, parser->scanner);
}

guint
py_parser_get_option (PYParser  *parser)
{
    return yyget_extra (parser->scanner);
}

