#include "parser.h"

int tokenToIndex(int t) {
    switch(t) {
        case TOKEN_EOF: return 0;
        case TOKEN_ID: return 1;
        case TOKEN_NUM: return 2;
        case TOKEN_INPUT: return 3;
        case '+': return 4;
        case '-': return 5;
        case '*': return 6;
        case '=': return 7;
        case ',': return 8;
        case '(': return 9;
        case ')': return 10;
    }
    return 11;
}

const rule_t* (*buildParsingTable())[TERMINAL_COUNT] {
    const rule_t* (*pt)[TERMINAL_COUNT] = (const rule_t* (*)[TERMINAL_COUNT]) \
                                    malloc(sizeof(rule_t*) * NON_TERMINAL_COUNT * TERMINAL_COUNT);
    memset(pt, 0, sizeof(rule_t*) * NON_TERMINAL_COUNT * TERMINAL_COUNT);
    
    // ----------------------------
    // Initialising CFG productions
    // ----------------------------
    
    // S -> CE eof
    static const rule_t rule1 = {2, {CFG_NT_CE, TOKEN_EOF}};
    
    // CE -> AE CE'
    static const rule_t rule2 = {2, {CFG_NT_AE, CFG_NT_CED}};
    
    // CE' -> , AE CE' 
    static const rule_t rule3 = {3, {',', CFG_NT_AE, CFG_NT_CED}};
    
    // AE -> id AE'
    static const rule_t rule4 = {2, {TOKEN_ID, CFG_NT_AED}};
    
    // AE -> PE
    static const rule_t rule5 = {1, {CFG_NT_PE}};
    
    // AE' -> ME'PE'
    static const rule_t rule6 = {2, {CFG_NT_MED, CFG_NT_PED}};
    
    // AE' -> = AE
    static const rule_t rule7 = {2, {'=', CFG_NT_AE}};  

    // PE -> ME PE'
    static const rule_t rule9 = {2, {CFG_NT_ME, CFG_NT_PED}};
    
    // PE' -> + ME PE' 
    static const rule_t rule10 = {3, {'+', CFG_NT_ME, CFG_NT_PED}};
    
    // ME -> BE ME'
    static const rule_t rule11 = {2, {CFG_NT_BE, CFG_NT_MED}};
    
    // ME' -> * BE ME' 
    static const rule_t rule12 = {3, {'*', CFG_NT_BE, CFG_NT_MED}};
    
    // CE' -> epsilon
    // PE' -> epsilon
    // ME' -> epsilon
    static const rule_t rule13 = {0, {0}};
    
    // BE -> (CE) 
    static const rule_t rule14 = {3, {'(', CFG_NT_CE, ')'}};
    
    // BE -> id
    static const rule_t rule15 = {1, {TOKEN_ID}};
    
    // BE -> num
    static const rule_t rule16 = {1, {TOKEN_NUM}};
    
    // BE -> r
    static const rule_t rule17 = {1, {TOKEN_INPUT}};    

    // ------------------------------
    // Initialising the Parsing Table
    // ------------------------------
        
    pt[CFG_NT_S][tokenToIndex(TOKEN_INPUT)] = &rule1;
    pt[CFG_NT_S][tokenToIndex(TOKEN_ID)] = &rule1;
    pt[CFG_NT_S][tokenToIndex(TOKEN_NUM)] = &rule1;
    pt[CFG_NT_S][tokenToIndex('(')] = &rule1;
    
    pt[CFG_NT_CE][tokenToIndex(TOKEN_INPUT)] = &rule2;
    pt[CFG_NT_CE][tokenToIndex(TOKEN_ID)] = &rule2;
    pt[CFG_NT_CE][tokenToIndex(TOKEN_NUM)] = &rule2;
    pt[CFG_NT_CE][tokenToIndex('(')] = &rule2;   

    pt[CFG_NT_CED][tokenToIndex(TOKEN_EOF)] = &rule13;
    pt[CFG_NT_CED][tokenToIndex(')')] = &rule13; 
    pt[CFG_NT_CED][tokenToIndex(',')] = &rule3; 
    
    pt[CFG_NT_AE][tokenToIndex(TOKEN_ID)] = &rule4;
    pt[CFG_NT_AE][tokenToIndex(TOKEN_INPUT)] = &rule5;
    pt[CFG_NT_AE][tokenToIndex(TOKEN_NUM)] = &rule5;
    pt[CFG_NT_AE][tokenToIndex('(')] = &rule5;
    
    pt[CFG_NT_AED][tokenToIndex('=')] = &rule7;
    pt[CFG_NT_AED][tokenToIndex('*')] = &rule6;
    pt[CFG_NT_AED][tokenToIndex('+')] = &rule6;
    pt[CFG_NT_AED][tokenToIndex(TOKEN_EOF)] = &rule6;
    pt[CFG_NT_AED][tokenToIndex(',')] = &rule6;
    pt[CFG_NT_AED][tokenToIndex(')')] = &rule6;
    
    pt[CFG_NT_PE][tokenToIndex(TOKEN_ID)] = &rule9;
    pt[CFG_NT_PE][tokenToIndex(TOKEN_INPUT)] = &rule9;
    pt[CFG_NT_PE][tokenToIndex(TOKEN_NUM)] = &rule9;
    pt[CFG_NT_PE][tokenToIndex('(')] = &rule9;
    
    pt[CFG_NT_PED][tokenToIndex(',')] = &rule13;
    pt[CFG_NT_PED][tokenToIndex(TOKEN_EOF)] = &rule13;
    pt[CFG_NT_PED][tokenToIndex('+')] = &rule10;
    pt[CFG_NT_PED][tokenToIndex(')')] = &rule13; 

    pt[CFG_NT_ME][tokenToIndex(TOKEN_ID)] = &rule11;
    pt[CFG_NT_ME][tokenToIndex(TOKEN_INPUT)] = &rule11;
    pt[CFG_NT_ME][tokenToIndex(TOKEN_NUM)] = &rule11;
    pt[CFG_NT_ME][tokenToIndex('(')] = &rule11;
    
    pt[CFG_NT_MED][tokenToIndex(',')] = &rule13;
    pt[CFG_NT_MED][tokenToIndex('*')] = &rule12;
    pt[CFG_NT_MED][tokenToIndex('+')] = &rule13;
    pt[CFG_NT_MED][tokenToIndex(TOKEN_EOF)] = &rule13;
    pt[CFG_NT_MED][tokenToIndex(')')] = &rule13;  
    
    pt[CFG_NT_BE][tokenToIndex(TOKEN_INPUT)] = &rule17;
    pt[CFG_NT_BE][tokenToIndex(TOKEN_NUM)] = &rule16;
    pt[CFG_NT_BE][tokenToIndex(TOKEN_ID)] = &rule15;
    pt[CFG_NT_BE][tokenToIndex('(')] = &rule14;
    
    return pt;     
}

bool isTerminal(int v) {
    switch(v) {
        case TOKEN_INPUT:
        case TOKEN_NUM:
        case TOKEN_ID:
        case '(':
        case ',':
        case '+':
        case '-':
        case '*':
        case ')':
        case '=':
        case TOKEN_EOF:
            return true;
        default:
            return false;
    }
}

bool parse() {
    stack st;
    const rule_t *r;
    int stack_top;
    int col_idx;
    bool rejected = false;
    
    const rule_t* (*pt)[TERMINAL_COUNT] = buildParsingTable();
    init(&st);
    push(&st, -1);
    push(&st, CFG_NT_S);
    
    getNextToken();
    while (1) {
        top(&st, &stack_top);

        if (stack_top == -1) {
            if (token.tokenClass != TOKEN_EOF) {
                rejected = true;
            }
            break;
        }
        
        if (isTerminal(stack_top)) {
            if (stack_top == token.tokenClass) {
                getNextToken();
                pop(&st);
                continue;
            }
            else {
                rejected = true;
                break;
            }
        }
            
        col_idx = tokenToIndex(token.tokenClass);
        if (pt[stack_top][col_idx] == NULL) {
            rejected = true;
            break;
        }
        
        r = pt[stack_top][col_idx];
        pop(&st);
        for (int i=r->len - 1; i>=0; i--) {
            push(&st, r->rule[i]);
        }
         
    }

    free(pt);
    return !rejected;    
}

