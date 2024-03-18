#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1064

typedef struct Stack{ 
	int data[MAX_SIZE];
	int size;
	int top; 
} Stack;

bool is_empty(Stack *stack) {
	return stack->top == -1;
}

bool is_full(Stack *stack) {
	return stack->top == MAX_SIZE - 1;
}

void init_stack(Stack *stack) {
	stack->top = -1; 
	stack->size = 0;
}

void inc_stack(Stack *stack, int val) {
	if (is_full(stack)) {
		printf("Stack overflow");
		exit(EXIT_FAILURE);
	}

	stack->data[++stack->top] = val;
	stack->size++;
}

void peek_stack(Stack *stack) {
	if (is_empty(stack)) {
		printf("Error, stack is empyty");
	}

	printf("Stack top: %d", stack->data[stack->top]);
}

int pop_stack(Stack *stack) {
	if (is_empty(stack)) {
		printf("Error, stack is empyty");
	}

	int top = stack->data[stack->top];
	stack->top--;

	return top;
}

void print_stack(Stack *stack) {
	if (is_empty(stack)) {
		printf("Error, stack is empyty");
	}

	for  (int i = 0; i < stack->size; i++) {
		printf("[%d]\n", stack->data[i]);
	}
}

int main() {

	Stack stack;

	init_stack(&stack);
	inc_stack(&stack, 3);
	inc_stack(&stack, 2);
	inc_stack(&stack, 5);
	inc_stack(&stack, 2);

	print_stack(&stack);

	return 0;
}