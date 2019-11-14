%{
#include <stdio.h>
#define FC 301
#define OK 1
#define ERRTOK 1
#define ERR 0
#define UNDEF -1
int S();
int E();
int F();
int H();
int token=UNDEF;
%}
%option noyywrap
FC [0-9]*\.[0-9]+
%%
"\n" { return (int)'\n'; }
"*" { return (int)'*'; }
"+" { return (int)'+'; }
{FC} { return FC; }
[ \t] { ; }
. { return ERRTOK; }
%%
int H(){
if(token == UNDEF) token = yylex();
if(token == '+' || token == '*') {
token = UNDEF;
return F();
}
return ERR;
}
int F(){
if(token == UNDEF) token = yylex();
if(token == '\n' || token == '+' || token == '*') return OK;
if(token == FC && E() == OK) return H();
else return ERR;
}
int E(){
if(token == UNDEF) token = yylex();
if(token == FC) {
token = UNDEF;
return F();
}
else return ERR;
}
int S(){
if(token == UNDEF) token = yylex();
if(token == FC) {
if(E() == OK){
if(token == UNDEF) token = yylex();
if(token == '\n') return OK;
else return ERR;
}
}
return ERR;
}
int main(){
if(S() == OK) printf("Accept\n");
else printf("Reject\n");
return 0;
}
