#include "lex.h"
#include "parser.h"
#include "backend.h"

int main() {
    fgets(expr, 1000, stdin);
    ASTnode_t *ptr;
    initParserBackend(); // initialize symbol table
    if (parser(&ptr)) {
        int ans = compute(ptr);
        if (!invalid_expr)
            printf("%d\n", ans);
    }
    else {
        printf("Invalid expression.\n");
    }
}
