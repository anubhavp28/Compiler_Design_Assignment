%{
#include <stdio.h>
%}

number [0-9]+
float [0-9]+\.[0-9]+
operator [-+/*]

%%
{number} {printf("(NUMBER: %s) ", yytext); }
{float} {printf("(FLOAT: %s) ", yytext); }
{operator} {printf("(OPERATOR: %s) ", yytext); }
. {}
%%

int main() {
    yylex();
    return 0;
}
