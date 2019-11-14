%{
#include <stdio.h>
#include <stdlib.h>
#include "218.tab.h++"
%}

%option yylineno
%option noyywrap

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

{comment} { }
{while} { return WHILE; }
{do} { return DO; }
{if} { return IF; }
{then} { return THEN; }
{else} { return ELSE; }
{int} { return INTTYPE; }
{real} { return FLOATTYPE; }
{nop} { return NOP; }
{print} { return PRINT; }
{read} { return READ; }
{identifier} { strcpy(yylval.varName, yytext); return ID; }
{string} { return STRING; }
{integer} { return IC; }
{float} { return FC; }

{dequal} { return DEQL;}
"+" { return (int)'+'; }
"-" { return (int)'-'; }
"*" { return (int)'*'; }
"/" { return (int)'/'; }
"<" { return (int)'<'; }
">" { return (int)'>'; }
"(" { return (int)'('; }
")" { return (int)')'; }
"=" { return (int)'='; }
";" { return (int)';'; }
"&" { return (int)'&'; }
"|" { return (int)'|'; }
"~" { return (int)'~'; }
":" { return (int)':'; }

{whitespace} {}
. {  }
%%
