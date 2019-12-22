#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}node;

void search(node* n, int item){
	int pos = 0;
	while(n!=NULL && n->data!=item){
		pos++;
		n=n->next;
	}

	if(n==NULL){
		printf("item[%d] not found\n", item);
		return;
	}

	printf("item[%d] @ position[%d]\n", item, pos);
}

void push(node** headref, int data){
	node* newnode = (node*)malloc(sizeof(node));
	newnode->data=data;
	newnode->next=*headref;
	*headref=newnode;
}

void main(){
	node* head = NULL;
	push(&head,10);
	push(&head,12);
	push(&head,13);
	push(&head,15);
	push(&head,14);
	push(&head,16);
	push(&head,17);
	push(&head,18);
	push(&head,19);
	push(&head,23);
	push(&head,20);
	push(&head,34);
	push(&head,1);
	push(&head,80);

	search(head, 17);
	search(head, 10);
	search(head, 80);
	search(head, 12);
	search(head, 100);
}