#ifndef _PARSER_H
#define _PARSER_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "lex.h"

#define RULE_LEN 150
#define TERMINAL_COUNT 100
#define NON_TERMINAL_COUNT 15
#define CFG_NT_S        0
#define CFG_NT_CE       1
#define CFG_NT_CED      2
#define CFG_NT_AE       3
#define CFG_NT_AED      4
#define CFG_NT_PE       5
#define CFG_NT_PED      6
#define CFG_NT_ME       7
#define CFG_NT_MED      8
#define CFG_NT_BE       9
#define CFG_T_EPSILON   10

typedef struct{
    int len;                 // length of right-hand side of the rule
    int rule[RULE_LEN];      // code sequence of terminals and
                             // non-terminals
}rule_t;

int tokenToIndex(int);
const rule_t* (*buildParsingTable())[TERMINAL_COUNT];
bool isTerminal(int); 
bool parse();

#endif
