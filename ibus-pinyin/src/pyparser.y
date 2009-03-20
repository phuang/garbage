/* vim:set et sts=4: */

%{
#include <stdio.h>
#include <glib.h>
#include "lex.yy.h"
#include "pinyin.h"

#ifndef DEBUG
#  undef g_debug
#  define g_debug(args...)
#endif

struct pywords_t {
    GList *list;
    guint len;
};

static void yyerror (gint *skip, GList **list, void *scanner, char *s);
%}


%start input

%union
{
    struct pinyin_t *py;
    struct {
        GList *list;
        gint len;
    } pys;
    gint skip;
}

%type  <pys>   pywords
%type  <py>    pyword
%type  <skip>  skip_chars
%token <py>    PINYIN
%token <py>    SHENGMU
%token SKIP

%parse-param {gint *skip}
%parse-param {GList **list}
%parse-param {void *scanner}
%lex-param   {void *scanner}


%left '\''

%%

input:
    {
        g_debug ("input = None\n");
        *list = NULL;
        *skip = 0;
    }
    | error
    {
        g_debug ("error");
    }
    |   skip_chars pywords
    {
        g_debug ("input = skip chars + pywords\n");
        *list = $2.list;
        *skip = $1;
    }
    |   pywords
    {
        g_debug ("input = pywords\n");
        *list = $1.list;
        *skip = 0;
    }
    ;
skip_chars:
        SKIP
    {
        $$ = 1;
    }
    |   '\''
    {
        $$ = 1;
    }
    |   skip_chars SKIP
    {
        g_debug ("skip_chras = skip_chars +  SKIP");
        $$ = $1 + 1;
    }
    |   skip_chars '\''
    {
        g_debug ("skip_chras = skip_chars +  '");
        $$ = $1 + 1;
    }
    |   pywords skip_chars
    {
        g_debug ("skip_chras = pywords + skip_chars");
        $$ = $1.len + $2;
        py_parser_free_result ($1.list);
    }
    ;
pywords:
        pyword
    {
        g_debug ("pywords = pyword");
        $$.list = g_list_append (NULL, $1);
        $$.len = $1->len;
    }
    |   pywords pyword
    {
        g_debug ("pywords = pywords + pyword");
        $$.list = g_list_prepend ($1.list, $2);
        $$.len = $1.len + $2->len;
    }
    |   pywords '\'' pyword
    {
        g_debug ("pywords = pywords + ' + pyword");
        $$.list = g_list_prepend ($1.list, $3);
        $$.len = $1.len + 1 + $3->len;
    }
    |   pywords pywords
    {
        g_debug ("pywords = pywords + pywords");
        $$.list = g_list_concat ($2.list, $1.list);
        $$.len = $2.len + $1.len;
    }
    ;
pyword:
        PINYIN
    {
        $$ = $1;
    }
    |   SHENGMU
    {
        $$ = $1;
    }
    ;

%%

static void yyerror (gint *skip, GList **list, void *scanner, char *s)
{
    g_debug (s);
}
