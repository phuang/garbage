/* vim:set et sts=4: */
%{
#include <stdio.h>
#include <glib.h>
#include "pinyin.h"
#include "pyparser.h"

#define DEBUG(args...)
// #define DEBUG g_debug

static void yyerror (gint *len, GArray **array, void *scanner, char *s);
static GArray *pinyin_array_reverse (GArray *array);

extern int yylex (void * scanner);

%}


%start input

%union
{
    struct pinyin_t *py;
    struct {
        GArray *array;
        gint len;
    } pys;
    struct pinyin_t *list[16];
    gint skip;
}

%type  <pys>   pywords
%type  <py>    pyword

%token <py>    PINYIN
%token <py>    SHENGMU
%token <list> PINYIN_LIST
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
    |   pywords pyword
    {
        DEBUG ("pywords pyword      => pywords");
        $$.array = g_array_append_val ($1.array, $2);
        $$.len = $2->len + $1.len;
    }
    |   pywords '\'' pyword
    {
        DEBUG ("pywords ' pyword    => pywords");
        $$.array = g_array_append_val ($1.array, $3);
        $$.len = $1.len + 1 + $3->len;
    }
    |   PINYIN_LIST
    {
         gint i;

        $$.array = g_array_sized_new (TRUE, FALSE, sizeof (struct pinyin_t *), 32);
        $$.len = 0;

        for (i = 0; $1[i] != NULL; i++) {
            g_array_append_val ($$.array, $1[i]);
            $$.len += PINYIN_LEN ($1[i]);
        }
    }
    |   pywords PINYIN_LIST
    {
        gint i;
        $$ = $1;

        for (i = 0; $2[i] != NULL; i++) {
            g_array_append_val ($$.array, $2[i]);
            $$.len += PINYIN_LEN ($2[i]);
        }
    }
    |   pywords '\'' PINYIN_LIST
    {
        gint i;
        $$ = $1;
        $$.len += 1;

        for (i = 0; $3[i] != NULL; i++) {
            g_array_append_val ($$.array, $3[i]);
            $$.len += PINYIN_LEN ($3[i]);
        }
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
