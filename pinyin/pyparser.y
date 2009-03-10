%{
#include <stdio.h>
#include <glib.h>
#include "pinyin.h"

void yyerror (void *scanner, GList **list, char *);
%}


%start list

%union
{
	struct pinyin_t *py;
	GList *list;
}

%type <list>  pywords
%type <py>  pyword
%token <py>  PINYIN
%token <py>  SHENGMU

%parse-param {GList **list}
%parse-param {void *scanner}
%lex-param {void *scanner}


%left '\''

%%

list:
	{
		*list = NULL;
	}
	|	pywords
	{
		*list = $1;
	}
	|	'\'' pywords
	{
		*list = $2;
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

void yyerror (void *scanner, GList **list, char *s)
{
	fprintf(stderr, "%s\n",s);
}

int yywrap(void *scanner, GList **list)
{
	return(1);
}

