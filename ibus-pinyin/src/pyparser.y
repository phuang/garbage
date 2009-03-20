%{
#include <stdio.h>
#include <glib.h>
#include "pinyin.h"

static void yyerror (gint *skip, GList **list, void *scanner, char *s);
%}


%start list

%union
{
	struct pinyin_t *py;
	GList *list;
	gint skip;
}

%type  <list>  pywords
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

list:
	{
		*list = NULL;
		*skip = 0;
	}
	|	skip_chars pywords
	{
		*list = $2;
		*skip = $1;
	}
	|	pywords
	{
		*list = $1;
		*skip = 0;
	}
	;
skip_chars:
	{
		$$ = 0;
	}
	|	skip_chars SKIP
	{
		$$ += 1;
	}
	;
pywords:
		pyword
	{
		$$ = g_list_append (NULL, $1);
	}
	|	pywords '\'' pyword
	{
		$$ = g_list_prepend ($1, $3);
	}
	|	pywords pyword
	{
		$$ = g_list_prepend ($1, $2);
	}
	;
pyword:
		PINYIN
	{
		$$ = $1;
	}
	|	SHENGMU
	{
		$$ = $1;
	}
	;

%%

static void yyerror (gint *skip, GList **list, void *scanner, char *s)
{
	fprintf(stderr, "%s\n",s);
	GList *p;

	for (p = *list; p != NULL; p ++) {
		g_slice_free (struct pinyin_t, p->data);
	}
	g_list_free (*list);

	*list = NULL;
}

int yywrap(void *scanner, gint *skip, GList **list)
{
	return(1);
}

