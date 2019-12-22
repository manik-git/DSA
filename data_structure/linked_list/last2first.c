/*
Write a function that moves the last element to the front in a given Singly Linked List. 
For example, if the given Linked List is 1->2->3->4->5, 
then the function should change the list to 5->1->2->3->4.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}node;

void last2first(node** headref){
	if(*headref == NULL || (*headref)->next == NULL) // empty list or single node list
		return;
	node* prev = NULL, *curr = *headref;
	while(curr->next!=NULL){
		prev=curr;
		curr=curr->next;
	}
	curr->next=*headref;
	prev->next=NULL;
	*headref=curr;
}

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

void main(){
	node* head = NULL;
	push(&head,5);
	push(&head,4);
	push(&head,3);
	push(&head,2);
	push(&head,1);
	print(head);
	last2first(&head);
	print(head);
}