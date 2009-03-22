/* vim:set et sts=4: */
%{
#include <stdio.h>
#include <glib.h>
#include "pinyin.h"
#include "pyparser.h"
#include "pyscanner.h"

#define DEBUG(args...)
// #define DEBUG g_debug

static void yyerror (gint *len, GArray **array, void *scanner, char *s);
static GArray *pinyin_array_reverse (GArray *array);

%}


%start input

%union
{
    struct pinyin_t *py;
    struct {
        GArray *array;
        gint len;
    } pys;
    gint skip;
}

%type  <pys>   pywords
%type  <py>    pyword

%token <py>    PINYIN
%token <py>    SHENGMU
%token SKIP

%parse-param {gint *len}
%parse-param {GArray **array}
%parse-param {void *scanner}
%lex-param   {void *scanner}

%left '\''

%%

input:
    {
        DEBUG ("NULL                => input\n");
        *array = g_array_sized_new (TRUE, FALSE, sizeof (struct pinyin_t *), 32);
        *len = 0;
    }
    |   error pywords
    {
        DEBUG ("error + pywords     => input\n");
        
        *array = pinyin_array_reverse ($2.array);
        *len = $2.len;
        
        yyerrok;
    }
    |   pywords
    {
        DEBUG ("pywords             => input\n");
        *array = pinyin_array_reverse ($1.array);
        *len = $1.len;
    }
    ;
pywords:
        pyword
    {
        DEBUG ("pyword              => pywords");
        $$.array = g_array_sized_new (TRUE, FALSE, sizeof (struct pinyin_t *), 32);
        g_array_append_val ($$.array, $1);
        $$.len = $1->len;
    }
    |   pywords '\'' pyword
    {
        DEBUG ("pywords ' pyword    => pywords");
        $$.array = g_array_append_val ($1.array, $3);
        $$.len = $1.len + 1 + $3->len;
    }
    |   pywords pyword
    {
        DEBUG ("pywords pyword      => pywords");
        $$.array = g_array_append_val ($1.array, $2);
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

static void
yyerror (gint *len, GArray **array, void *scanner, char *s)
{
    DEBUG (s);
    if (*array) {
        py_parser_free_result (*array);
    }
    *array = NULL;
    *len = 0;
}

static GArray *
pinyin_array_reverse (GArray *array)
{
    gint i;
    struct pinyin_t *tmp;

    for (i = 0; i < array->len >> 1; i++) {
        tmp = g_array_index (array, struct pinyin_t *, i);
        g_array_index (array, struct pinyin_t *, i) = g_array_index (array, struct pinyin_t *, array->len - i - 1);
        g_array_index (array, struct pinyin_t *, array->len - i - 1) = tmp;
    }

    return array;
}
