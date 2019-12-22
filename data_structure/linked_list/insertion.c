#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
}node;

void insert(node* prevnode, int data){

	node* newnode = (node*)malloc(sizeof(node));

	newnode->data = data;
	newnode->next = NULL;

	if(prevnode==NULL){
		printf("prev node cant be null");
		return;
	}

	newnode->next=prevnode->next;
	prevnode->next=newnode;
}

void push(node** headref, int data){
	node* newnode = (node*)malloc(sizeof(node));

	newnode->data = data;
	newnode->next = *headref;
	*headref=newnode;
}

void print(node* headref){
	while(headref!=NULL){
		printf("%d\n", headref->data);
		headref=headref->next;
	}
	printf("done.\n");
}

void main(){

	node* head = NULL;

	push(&head, 5);
	push(&head, 3);
	push(&head, 1);

	print(head);

	insert(head, 2);

	print(head);

	insert(head->next->next, 4);

	print(head);
}