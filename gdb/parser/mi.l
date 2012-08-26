%{
#include <stdlib.h>
#include "mi.h"

void yyerror(char*);
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
