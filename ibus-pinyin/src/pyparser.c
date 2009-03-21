/* vim:set et sts=4: */
#include <glib.h>
#include "lex.yy.h"
#include "pinyin.h"
#include "pyparser.h"

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

extern int yyparse (gint *skip, GList **list, void *scanner);

gint
py_parser_parse (PYParser    *parser,
                 const gchar *str,
                 gint         len,
                 GList       **list)
{
    YY_BUFFER_STATE b;
    GList *result;
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

    *list = result;
    yy_delete_buffer (b, parser->scanner);

    return retval;
}

void
py_parser_free_result (GList *result)
{
    GList *p;

    for (p = result; p != NULL; p = p->next) {
        g_slice_free (struct pinyin_t, p->data);
    }

    g_list_free (result);
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

