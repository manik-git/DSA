#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}node;

void push ( struct node** headref, int data ){

	node* newnode = (node*)malloc(sizeof(node));

	newnode->data = data;
	newnode->next=*headref;
	*headref=newnode;
}

void print ( node* headref ){
	while(headref!=NULL){
		printf("%d\n", headref->data);
		headref=headref->next;
	}
	printf("\ndone.\n");
}

int main(){

	node* head = NULL;
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);
	print(head);
}