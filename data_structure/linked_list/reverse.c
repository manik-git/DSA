#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}node;

void reverse(node** headref){
	node* prev = NULL;
	node* curr = *headref;
	node* next = NULL;

	while(curr!=NULL){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*headref = prev;
}

void push(node** headref, int data){
	node* newnode = (node*)malloc(sizeof(node));
	newnode->data=data;
	newnode->next=*headref;
	*headref=newnode;
}

void print(node* n){
	printf("----\nlinked list:\t");
	while(n!=NULL){
		printf("%d\t",n->data);
		n=n->next;
	}
	printf("\n----\n");
}

void main(){
	node* head = NULL;
	push(&head,5);
	push(&head,40);
	push(&head,3);
	push(&head,2);
	push(&head,13);

	print(head);

	reverse(&head);

	print(head);
}