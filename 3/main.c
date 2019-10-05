#include "lex.h"
#include "parser.h"
#include "backend.h"

int main() {
    scanf("%s", expr);
    ASTnode_t *ptr;
    if (parser(&ptr)) {
        int ans = compute(ptr);
        printf("%d\n", ans);
    }
    else {
        printf("Invalid expression.\n");
    }
}
