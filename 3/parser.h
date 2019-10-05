// parse.h header file for the parser
#ifndef PARSER_H
#define PARSER_H

#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    char type;                  // I: internal, D: data, R: read
    unsigned int val;           // for a node of type D
    struct node *left, *right;  // pointers to left and right
                                // subtrees for a node of type I
    char op;                    // the operator in node type I
} ASTnode_t;

extern int parser(ASTnode_t **);    // returns 1 on success,
                                    // returns 0 on failure.
#endif
