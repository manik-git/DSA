#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
}node;

void push(node** headref, int data){
	node* newnode = (node*)malloc(sizeof(node));
	newnode->data = data;
	newnode->next = *headref;

	node* temp = *headref;

	if(*headref!=NULL){
		while(temp->next!=*headref)
			temp=temp->next;
		temp->next=newnode;
	} else {
		newnode->next=newnode;
	}

	*headref = newnode;
}

void print(node* head){
	node* n = head;
	printf("----\nhead : %p\n", (void *)head);
	if(!head)
		return;
	do{
		printf("%p : %d -> %p\n", (void *)n, n->data, (void *)n->next);
		n=n->next;
	}while(n!=head);
	printf("\n----\n");
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