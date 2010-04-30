%{
#include <string>
%}

%union {
    int integer;
    std::string str;
};

%token <integer> INTEGER
%token <str> STRING
%token <str> SYMBOL_NAME
%token <str> KEYCODE_NAME

// define options
%token OPT_DEFAULT
%token OPT_PARTIAL
%token OPT_HIDDEN
%token OPT_ALPHANUMERIC_KEYS
%token OPT_MODIFIER_KEYS
%token OPT_KEYPAD_KEYS
%token OPT_FUNCTION_KEYS
%token OPT_ALTERNATE_GROUP

%token XKB_SYMBOLS
%token INCLUDE
%token NAME
%token KEY

%token GROUP1
%token GROUP2
%token GROUP3
%token GROUP4

%%

symbols:
    symbols_declare symbols_body ';';

symbols_declare:
    options symbols_name
    ;

symbols_name:
    XKB_SYMBOLS STRING
    ;

options:
    option |
    options option
    ;

option:
    OPT_DEFAULT |
    OPT_PARTIAL |
    OPT_HIDDEN |
    OPT_ALPHANUMERIC_KEYS |
    OPT_MODIFIER_KEYS |
    OPT_KEYPAD_KEYS |
    OPT_FUNCTION_KEYS |
    OPT_ALTERNATE_GROUP
    ;

symbols_body:
    '{' symbols_items '}'
    ;
symbols_items:
    symbols_item ';' |
    symbols_items symbols_item ';'
    ;

symbols_item:
    KEY KEYCODE_NAME '{' '[' symbol_names ']' '}' |
    NAME '['  group ']' '=' STRING |
    INCLUDE STRING
    ;

symbol_names:
    SYMBOL_NAME |
    symbol_names ',' SYMBOL_NAME
    ;

group:
    GROUP1 |
    GROUP2 |
    GROUP3 |
    GROUP4
    ;
