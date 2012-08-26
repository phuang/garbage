%{
#include <stdlib.h>
#include "mi.tab.h"

void yyerror (const char* s);

%}

%%

[1-9][0-9]*         {
                        yylval.integer = atoi(yytext);
                        return INTEGER;
                    }

\"(\\.|[^\\"])*\"   {
                        yylval.string = strdup(yytext);
                        return STRING;
                    }

%%

int yywrap(void) {
    return 1;
}
