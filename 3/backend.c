#include "backend.h"

int compute(ASTnode_t *node) {
    if (node->type=='D') 
        return node->val;
    else if (node->type=='I') {
        switch(node->op) {
            case '+': return compute(node->left) + compute(node->right);
            case '*': return compute(node->left) * compute(node->right);
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