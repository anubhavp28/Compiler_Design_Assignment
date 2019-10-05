#include <stdio.h>
#include "lex.h"
#include "parser.h"
#include "stack.h"

int main() {
    fgets(expr, 1000, stdin);
    if (parse())
        printf("Accepted\n");
    else
        printf("Rejected\n");
    return 0;    
}
