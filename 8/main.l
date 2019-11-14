%{
#include <stdio.h>
#include <stdlib.h>

#define TOKEN_FC 251
#define ACCEPTED 1005
#define PARSER_ERROR 1006

int currentToken;
%}

%option noyywrap

fc [0-9]*\.[0-9]+
newline [\n]
%%
{fc} { return TOKEN_FC; }
"+" { return (int)'+'; }
"*" { return (int)'*'; }
"\n" { return (int)'\n'; }
[ \t] { ; }
. { return 1; }

%%
int H();
int F();
int S();
int E();

int H() {
    if (currentToken == '+' || currentToken == '*') {
        currentToken = yylex();
        return F();
    }
    
    return PARSER_ERROR;
}

int S() {
    if (currentToken != TOKEN_FC) {
        return PARSER_ERROR;
    }
    
    if (E() == PARSER_ERROR) return PARSER_ERROR;
    
    if (currentToken != '\n') {
        return PARSER_ERROR;
    }
    
    return ACCEPTED;
}

int E() {
    if (currentToken != TOKEN_FC) {
        return PARSER_ERROR;
    }
    
    currentToken = yylex();
    return F();
}

int F() {
    if (currentToken == TOKEN_FC) {
        if (E() == ACCEPTED) return H();
        else return PARSER_ERROR;
    }
    
    if (currentToken == '\n' || currentToken == '+' || currentToken == '*') {
        return ACCEPTED;
    }
    
    return PARSER_ERROR;
}


int main(void) {
    currentToken = -1;
    currentToken = yylex();
    if (S() == ACCEPTED) printf("Accepted!\n");
    else printf("Rejected\n");
}


