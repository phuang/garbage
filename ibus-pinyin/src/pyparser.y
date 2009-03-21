/* vim:set et sts=4: */
%{
#include <stdio.h>
#include <glib.h>
#include "lex.yy.h"
#include "pinyin.h"
#include "pyparser.h"

#define DEBUG(args...)
// #define DEBUG g_debug

static void yyerror (gint *len, GList **list, void *scanner, char *s);
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
/*
%type  <skip>  skip_all
%type  <skip>  skip_pywords
%type  <skip>  skip_chars
*/
%token <py>    PINYIN
%token <py>    SHENGMU
%token SKIP

%parse-param {gint *len}
%parse-param {GList **list}
%parse-param {void *scanner}
%lex-param   {void *scanner}


%left '\''

%%

input:
    {
        DEBUG ("NULL                => input\n");
        *list = NULL;
        *len = 0;
    }
    |   error pywords
    {
        DEBUG ("error + pywords     => input\n");
        *list = $2.list;
        *len = $2.len;
        yyerrok;
    }
    |   pywords
    {
        DEBUG ("pywords             => input\n");
        *list = $1.list;
        *len = $1.len;
    }
    ;
pywords:
        pyword
    {
        DEBUG ("pyword              => pywords");
        $$.list = g_list_append (NULL, $1);
        $$.len = $1->len;
    }
    |   pywords '\'' pyword
    {
        DEBUG ("pywords ' pyword    => pywords");
        $$.list = g_list_prepend ($1.list, $3);
        $$.len = $1.len + 1 + $3->len;
    }
    |   pywords pyword
    {
        DEBUG ("pywords pyword      => pywords");
        $$.list = g_list_prepend ($1.list, $2);
        $$.len = $2->len + $1.len;
    }
    ;
pyword:
        PINYIN
    {
        DEBUG ("PINYIN              => pyword");
        $$ = $1;
    }
    |   SHENGMU
    {
        DEBUG ("SHENGMU             => pyword");
        $$ = $1;
    }
    ;

%%

static void yyerror (gint *len, GList **list, void *scanner, char *s)
{
    DEBUG (s);
    py_parser_free_result (*list);
    *list = NULL;
    *len = 0;
}

