#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}node;

void getNth(node* n, int N){

	for(int i = 0; n != NULL && i != N; i++ )
		n=n->next;

	if(n==NULL){
		printf("pos[%d] not found\n", N);
		return;
	}

	printf("item[%d] @ position[%d]\n", n->data, N);

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

	getNth(head, 0);
	getNth(head, 1);
	getNth(head, 12);
	getNth(head, 13);
	getNth(head, 100);
}