#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}node;

void push(node** headref, int data){
	node* newnode = (node*)malloc(sizeof(node));
	newnode->data=data;
	newnode->next=*headref;
	*headref=newnode;
}

void print(node* n){
	printf("----\n");
	while(n!=NULL){
		printf("%d\t",n->data);
		n=n->next;
	}
	printf("\n----\n");
}

void evenodd (node** headref){

}

void main(){
	node* head = NULL;
	push(&head,5);
	push(&head,4);
	push(&head,3);
	push(&head,12);
	push(&head,1);
	print(head);
	evenodd(&head);
	print(head);
}