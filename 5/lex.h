// lex.h the header file for the scanner
#ifndef LEX_H
#define LEX_H

#include <stdio.h>
#define TOKEN_EOF 256
#define TOKEN_NUM 257
#define TOKEN_ID  258
#define TOKEN_INPUT 259
typedef struct { int tokenClass; int val; } token_t;
extern token_t token;
extern char expr[1000];
extern void getNextToken(void);

#endif

