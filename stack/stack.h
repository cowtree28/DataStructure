#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

typedef struct Stack Stack;

Stack* stack_init(int capacity);
int stack_is_empty(const Stack* stack);
int stack_is_full(const Stack* stack);
int stack_push(Stack* stack, int value);
int stack_pop(Stack* stack, int* out);
int stack_peek(const Stack* stack, int* out);
int stack_size(const Stack* stack);
int stack_destroy(Stack* stack);
int stack_clear(Stack* stack);
int stack_copy(Stack* destination, const Stack* source);

#endif