// lex.h the header file for the scanner
#include <stdio.h>
#define END 256
#define NUM 257
typedef struct { int tokenClass; int val; } token_t;
extern token_t token;
extern char expr[1000];
extern void getNextToken(void);

