#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}node;

void append(node** headref, int data){
	node* newnode = (node*)malloc(sizeof(node));

	newnode->data = data;
	newnode->next = NULL;

	node* last = *headref;

	if(last==NULL){
		*headref=newnode;
		return;
	}

	while(last->next!=NULL){
		last=last->next;
	}

	last->next=newnode;
}

void insert(node* prev, int data){
	node* newnode = (node*)malloc(sizeof(node));

	newnode->data = data;
	newnode->next = NULL;

	if(prev==NULL){
		printf("prev cant be null\n");
		return;
	}

	newnode->next=prev->next;
	prev->next=newnode;
}

void push(node** headref, int data){
	node* newnode = (node*)malloc(sizeof(node));

	newnode->data = data;
	newnode->next = *headref;
	*headref = newnode;
}

void print(node* headref){
	while(headref!=NULL){
		printf("%d\n",headref->data);
		headref=headref->next;
	}
	printf("----\n");
}

void main(){
	node* head = NULL;

	push(&head,3);
	print(head);
	append(&head,5);
	insert(head,4);
	push(&head,1);
	insert(head,2);

	print(head);
}