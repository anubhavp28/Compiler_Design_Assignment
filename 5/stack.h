#ifndef _STACK_H
#define _STACK_H
#define STACK_SIZE 1000
#define STACK_ERROR 1
#define STACK_OK 0
typedef struct {
    int data[STACK_SIZE];
    int size;
} stack ;
void init(stack *);
int push(stack *, int);
int pop(stack *);
int top(stack *, int *);
int isEmpty(stack *);
int isFull(stack *);
#endif
