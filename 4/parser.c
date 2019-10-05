#include "parser.h"
#include "lex.h"

void parseExp(ASTnode_t *tpp) {
    if (token.tokenClass == '(') {
        ASTnode_t *p = (ASTnode_t *)malloc(sizeof(ASTnode_t));
        p->left = p->right = NULL;
        tpp->left = p;
        getNextToken();
        parseExp(tpp->left);
    }

    if (token.tokenClass == '*' || token.tokenClass == '+' || token.tokenClass == ',' || token.tokenClass == '=') {
        tpp->type = 'I';
        tpp->op = token.tokenClass;
        ASTnode_t *p = (ASTnode_t *)malloc(sizeof(ASTnode_t));
        p->left = p->right = NULL;
        tpp->right = p;
        getNextToken();
        parseExp(tpp->right);
    }

    if (token.tokenClass == NUM) {
        tpp->type = 'D';
        tpp->val = token.val;
        getNextToken();
        return;
    }

    if (token.tokenClass == ID) {
        tpp->type = 'V';
        tpp->val = token.val;
        getNextToken();
        return;
    }

    if (token.tokenClass == ')') {
        getNextToken();
        return;
    }

    if (token.tokenClass == 'r') {
        tpp->type = 'R';
        getNextToken();
        return;
    }

    if (token.tokenClass == END) {
        return;
    }
}

int parser(ASTnode_t **tpp) {
    getNextToken();
    if (token.tokenClass != END) {
        *tpp = (ASTnode_t *)malloc(sizeof(ASTnode_t));
        parseExp(*tpp);
        return 1;
    }
    return 0;
}
