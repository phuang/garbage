%{
#include <stdio.h>
%}

%union {
    int integer;
    char* string;
}

%token <integer> INTEGER;
%token <string> STRING;

%%

outputs:
      output
    | outputs output
    | /* NULL */
    ;

output:
      "(gdb)" nl
    | out_of_band_records "(gdb)" nl
    | out_of_band_records result_record "(gdb)" nl
    ;

result_record:
      opt_token '^' result_class nl
    | opt_token '^' result_class ',' results nl
    ;

out_of_band_records: 
      out_of_band_record
    | out_of_band_records out_of_band_record
    ;

out_of_band_record:
      async_record
    | stream_record
    ;

async_record:
      exec_async_output
    | status_async_output
    | notify_async_output
    ;

exec_async_output:
    opt_token '*' async_output
    ;

status_async_output:
    opt_token '+' async_output
    ;

notify_async_output:
    opt_token '=' async_output
    ;

async_output:
      async_class nl
    | async_class ',' results nl
    ;

result_class:
      "done"
    | "running"
    | "connected"
    | "error"
    | "exit"
    ;

async_class:
      "stopped"
    ;

variable:
    STRING
    ;

value:
      const
    | tuple
    | list
    ;
values:
      value
    | values ',' value
    ;

const:
    STRING
    ;

tuple:
      '{' '}'
    | '{' results '}'
    ;

list:
      '[' ']'
    | '[' values ']'
    | '[' results ']'
    ;

results:
      result
    | results ',' result
    ;

result:
    variable '=' value
    ;

stream_record:
      console_stream_output
    | target_stream_output
    | log_stream_output
    ;

console_stream_output:
    '~' STRING
    ;

target_stream_output:
    '@' STRING
    ;

log_stream_output:
    '&' STRING
    ;

nl:
      '\n'
    | "\r\n"
    ;

opt_token:
      token
    | /* NULL */
    ;

token:
    INTEGER
    ;
%%

void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}


int main(void) {
    yyparse();
    return 0;
}
