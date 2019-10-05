#include "stack.h"
#include <stdio.h>
void init(stack *st) {
    st->size = 0;
}

int push(stack *st, int val) {
    if (st->size == STACK_SIZE) return STACK_ERROR;
    st->data[st->size++] = val;
    return STACK_OK;
}

int pop(stack *st) {
    if (!st->size) return STACK_ERROR;
    st->size--;
    return STACK_OK;
}

int top(stack *st, int *var) {
    if (!st->size) return STACK_ERROR;
    *var = st->data[st->size - 1];
    return STACK_OK;
}

int isEmpty(stack *st) {
    return !st->size;
}

int isFull(stack *st) {
    return st->size == STACK_SIZE;
}
