%{
#include <stdio.h>
#include <stdlib.h>
#include "218.tab.h++"
%}

%option yylineno

string \"[a-zA-Z0-9 ]*\"
identifier [a-zA-Z][a-zA-Z0-9]*
integer [0-9]+
float ([0-9]+.[0-9]*|[0-9]*.[0-9]+)
whitespace [ \t\n]
while while
do do
if if
then then
else else
int int
real real
nop nop
print print
read read
dequal ==
comment (\/\/).*\n

%%

{comment} { printf("comment = %s\n", yytext); }
{while} { printf("%s", yytext); return WHILE; }
{do} { return DO; }
{if} { return IF; }
{then} { return THEN; }
{else} { return ELSE; }
{int} { return INTTYPE; }
{real} { return FLOATTYPE; }
{nop} { return NOP; }
{print} { return PRINT; }
{read} { return READ; }
{identifier} { printf("id = %s\n", yytext); return ID; }
{string} { printf("string = %s\n", yytext); return STRING; }
{integer} { return IC; }
{float} { return FC; }

{dequal} { printf("%s\n", yytext); return DEQL;}
"+" { printf("%s\n", yytext); return (int)'+'; }
"-" { printf("%s\n", yytext); return (int)'-'; }
"*" { printf("%s\n", yytext); return (int)'*'; }
"/" { printf("%s\n", yytext); return (int)'/'; }
"<" { printf("%s\n", yytext); return (int)'<'; }
">" { printf("%s\n", yytext); return (int)'>'; }
"(" { printf("%s\n", yytext); return (int)'('; }
")" { printf("%s\n", yytext); return (int)')'; }
"=" { printf("%s\n", yytext); return (int)'='; }
";" { printf("%s\n", yytext); return (int)';'; }
"&" { printf("%s\n", yytext); return (int)'&'; }
"|" { printf("%s\n", yytext); return (int)'|'; }
"~" { printf("%s\n", yytext); return (int)'~'; }
":" { printf("%s\n", yytext); return (int)':'; }

{whitespace} {}
. { printf("Unknow character : %s" , yytext); }
%%
