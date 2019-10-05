#include "backend.h"

bool invalid_expr;

void initParserBackend() {
    invalid_expr = false;
    initSymTab();
}

int compute(ASTnode_t *node) {
    if (invalid_expr) return INT_MAX;

    if (node->type=='D') 
        return node->val;
    else if (node->type=='V') {
        int p;
        if (getVal(node->val, &p)) 
            return p;
        else { 
            printf("Value of '%c' is not defined\n", node->val);
            invalid_expr = true;
            return INT_MAX; 
        }
    }
    else if (node->type=='I') {
        switch(node->op) {
            case '+': return compute(node->left) + compute(node->right);
            case '*': return compute(node->left) * compute(node->right);
            case ',': compute(node->left); return compute(node->right);
            case '=': return updateSymTab(node->left->val, compute(node->right));
        }
    }
    else {
        int x;
        printf("Value of r : ");
        scanf("%d", &x);
        return x;
    }
    return INT_MAX;
}