#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct stackNode{
	int data;
	struct stackNode* next;
}stackNode;

void push(stackNode** root, int data){
	stackNode* newnode = (stackNode*)malloc(sizeof(stackNode));
	newnode->data=data;
	newnode->next=*root;
	*root=newnode;
}

int pop(stackNode** root){
	if(*root==NULL){
		return INT_MIN;
	}
	stackNode* tmp = *root;
	int popped = (*root)->data;
	*root=(*root)->next;
	free(tmp);
	return popped;
}

void print(stackNode* root){
	printf("----\n");
	while(root){
		printf("%d\t", root->data);
		root=root->next;
	}
	printf("\n----\n");
}

int peek(stackNode* root){
	if(root==NULL)
		return INT_MIN;
	return root->data;
}

void main(){
	stackNode* root = NULL;
	printf("popped : %d\n", pop(&root));
	push(&root, 5);
	push(&root, 4);
	push(&root, 3);
	push(&root, 2);
	push(&root, 1);
	printf("peek : %d\n", peek(root));
	print(root);
	printf("popped : %d\n", pop(&root));
	print(root);
	printf("popped : %d\n", pop(&root));
	print(root);
	printf("peek : %d\n", peek(root));
	printf("popped : %d\n", pop(&root));
	printf("peek : %d\n", peek(root));
	print(root);
	printf("popped : %d\n", pop(&root));
	print(root);
	printf("popped : %d\n", pop(&root));
	print(root);
}