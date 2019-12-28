#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Stack{
	int top;
	unsigned capacity;
	int* array;
}Stack;

Stack* createStack(unsigned capacity){
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	stack->top = -1;
	stack->capacity = capacity;
	stack->array = (int*)malloc(stack->capacity * sizeof(int));
	return stack;
}

void push(Stack* stack, int data){
	if(stack->top == stack->capacity - 1)
		return;
	stack->array[++stack->top] = data;
}

int pop(Stack* stack){
	if(stack->top==-1)
		return INT_MIN;
	return stack->array[stack->top--];
}

void print(Stack* stack){
	printf("----\n");
	if(stack->top==-1)
		return;
	for(int i = 0; i <= stack->top ; i++){
		printf("%d\t",stack->array[i]);
	}
	printf("\n----\n");
}

int main(){
	Stack* stack = createStack(4);
	push(stack, 10);
	push(stack, 11);
	push(stack, 12);
	push(stack, 13);
	push(stack, 14);
	print(stack);
	pop(stack);
	print(stack);
	return 0;
}
