#include "lex.h"

token_t token;
char expr[1000];

void getNextToken(void) {
    static int i = 0;
    
    while (expr[i]=='\n' || expr[i]==' ')
        i++;

    // end of file token
    if (expr[i]=='\0') {
        token.tokenClass = TOKEN_EOF;
        return;
    }

    // integer token
    if (expr[i]>= '0' && expr[i]<='9') {
        int x = expr[i] - '0';
        i++;
        while(expr[i]>= '0' && expr[i]<='9') {
            x = x*10 + expr[i] - '0';
            i++;
        }
        token.tokenClass = TOKEN_NUM;
        token.val = x;
        return;
    }

    if (expr[i]!='r' && ((expr[i]>='a' && expr[i]<='z') || (expr[i]>='A' && expr[i]<='Z'))) {
        token.tokenClass = TOKEN_ID;
        token.val = expr[i];
        i++;
        return;
    }

    if (expr[i]=='r') {
        token.tokenClass = TOKEN_INPUT;
        i++;
        return;
    }
    
    // token is an operator
    token.tokenClass = expr[i];
    i++;
}
