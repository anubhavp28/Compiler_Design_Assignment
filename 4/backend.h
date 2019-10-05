#include "parser.h"
#include "symTab.h"
#include <limits.h>
#include <stdbool.h>
extern bool invalid_expr;
int compute(ASTnode_t *);
void initParserBackend();