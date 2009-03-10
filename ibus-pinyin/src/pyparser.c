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

extern int yyparse (GList **list, void *scanner);

GList *
py_parser_parse (PYParser *parser, const gchar *str)
{
    YY_BUFFER_STATE b;
    GList *result;
    gchar buf[8];
    strcpy (buf, str);
    g_strreverse (buf);

    b = yy_scan_string (buf, parser->scanner);
    if (yyparse (&result, parser->scanner) != 0) {
        result = NULL;
    }

    yy_delete_buffer (b, parser->scanner);

    return result;
}

