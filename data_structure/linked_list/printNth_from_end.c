#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}node;

int countNodes(node* n){
	int count = 0;

	while(n!=NULL){
		count++;
		n=n->next;
	}

	return count;
}

void getNthfromlast(node* n, int N){

	int len = countNodes(n);

	int K = len - N;

	for(int i = 0; n!=NULL && i!=K; i++)
		n=n->next;

	if(n==NULL){
		printf("position[%d]from end not found\n", N);
		return;
	}

	printf("item[%d] @ position[%d] from last\n", n->data, N);

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

	getNthfromlast(head, 1);
	getNthfromlast(head, 12);
	getNthfromlast(head, 13);
	getNthfromlast(head, 14);
	getNthfromlast(head, 100);
}