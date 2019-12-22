#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}node;

void countnodes(node* n){
	int count = 0;
	while(n!=NULL){
		count++;
		n=n->next;
	}
	printf("no. of nodes:\t%d\n", count);
}

void push(node** headref, int data){
	node* newnode = (node*)malloc(sizeof(node));
	newnode->data=data;
	newnode->next=*headref;
	*headref=newnode;
}

void main(){
	node* head = NULL;
	countnodes(head);
	push(&head,10);
	push(&head,11);
	countnodes(head);
	push(&head,12);
	push(&head,13);
	push(&head,14);
	countnodes(head);
	push(&head,15);
	push(&head,16);
	push(&head,17);
	countnodes(head);
	push(&head,18);
	push(&head,19);
	countnodes(head);
}