%{
#include <stdio.h>
#include <glib.h>

void yyerror (GList **list, char *);
%}


%start list

%union
{
	gchar *str;
	GList *list;
}

%type <list>  pywords
%type <str>  pyword
%token <str>  PINYIN
%token <str>  SHENGMU

%parse-param {GList **list}
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
	;
pywords:
		pyword
	{
		$$ = g_list_append (NULL, $1);
	}
	|   pywords pyword
	{
		$$ = g_list_prepend ($$, $2);
	}
	|	pywords '\'' pyword
	{
		$$ = g_list_prepend ($$, $3);
	}
	;
pyword:
		PINYIN
	{
		$$ = g_strreverse ($1);
	}
	|	SHENGMU
	{
		$$ = g_strreverse ($1);
	}
	;

%%

void yyerror (GList **list, char *s)
{
	fprintf(stderr, "%s\n",s);
}

int yywrap(GList **list)
{
	return(1);
}

