#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	struct node* prev;
	int data;
	struct node* next;
}node;

void push(node** headref, int data){
	node* newnode = (node*)malloc(sizeof(node));
	newnode->prev=NULL;
	newnode->data=data;
	newnode->next=NULL;

	if(*headref==NULL){
		*headref = newnode;
		return;
	}

	node* temp = *headref;

	while(temp->next!=NULL)
		temp=temp->next;

	temp->next = newnode;
	newnode->prev = temp;
}

void print(node* n){
	printf("----\nhead : %p\n", (void *)n);
	while(n!=NULL){
		printf("%p : %p <- %d -> %p\n", (void *)n, (void *)n->prev, n->data, (void *)n->next);
		n=n->next;
	}
	printf("----\n");
}

int main(){
	node* head = NULL;
	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);
	print(head);
	return 0;
}
