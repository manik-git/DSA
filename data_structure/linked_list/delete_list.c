// deleting complete linked list

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}node;

void deletelist(node** headref){
	if(*headref==NULL){
		printf("list is empty\n");
		return;
	}

	node* current = *headref, *nxt;

	while(current!=NULL){
		nxt=current->next;
		printf("deleting %d\n", current->data);
		free(current);
		current=nxt;
	}

	printf("list deleted\n");
}

void push(node** headref, int data){
	node* newnode = (node*)malloc(sizeof(node));

	newnode->data = data;
	newnode->next = *headref;
	*headref = newnode;
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
	deletelist(&head);
	push(&head,5);
	push(&head,4);
	push(&head,3);
	push(&head,2);
	push(&head,1);
	print(head);
	deletelist(&head);
}