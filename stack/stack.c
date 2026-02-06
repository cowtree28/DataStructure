#include "stack.h"

typedef struct {
	int* arr;
	int top;
	int capacity;
}Stack;

Stack* stack_init(int capacity) {
	if (capacity <= 0)
		return NULL;
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	if (stack == NULL) {
		return NULL;
	}
	
	stack->arr = (int*)malloc(sizeof(int) * capacity);
	if (stack->arr == NULL) {
		free(stack);
		return NULL;
	}

	stack->capacity = capacity;
	stack->top = -1;
	return stack;
}

int stack_is_empty(const Stack* stack) {
	return stack->top == -1;
}

int stack_is_full(const Stack* stack) {
	return stack->top == stack->capacity - 1;
}

int stack_push(Stack* stack, int value) {
	if (stack_is_full(stack))
		return -1;
	stack->arr[++stack->top] = value;
	return 0;
}

int stack_pop(Stack* stack, int* out) {
	if (stack_is_empty(stack))
		return -1;
	*out = stack->arr[stack->top--];
	return 0;
}

int stack_peek(const Stack* stack, int* out) {
	if (stack_is_empty(stack))
		return -1;
	*out = stack->arr[stack->top];
	return 0;
}

int stack_size(const Stack* stack) {
	return stack->top + 1;
}

int stack_destroy(Stack* stack) {
	free(stack->arr);
	free(stack);
	return 0;
}

int stack_clear(Stack* stack) {
	stack->top = -1;
	return 0;
}

int stack_copy(Stack* destination, const Stack* source) {
	if (destination->capacity < source->top + 1)
		return -1;
	for (int i = 0; i <= source->top; i++) {
		destination->arr[i] = source->arr[i];
	}
	destination->top = source->top;
	return 0;
}