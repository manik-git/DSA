/*
Given two lists sorted in increasing order, 
create and return a new list representing the intersection of the two lists. 
The new list should be made with its own memory — 
the original lists should not be changed.
For example, let the first linked list be 1->2->3->4->6
and second linked list be 2->4->6->8, 
then your function should create and return a third list as 2->4->6.
*/

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

void intersection(node* h1, node* h2){
	node* h3 = NULL;
	while(h1 && h2){
		if(h1->data == h2->data){
			push(&h3, h1->data);
			h1=h1->next;
			h2=h2->next;
		} else if(h1->data < h2->data) {
			h1=h1->next;
		} else {
			h2=h2->next;
		}
	}
	print(h3);
}

void main(){
	node* head1 = NULL, *head2 = NULL;
	push(&head1,5);
	push(&head1,4);
	push(&head1,3);
	push(&head1,2);
	push(&head1,1);
	print(head1);
	push(&head2,10);
	push(&head2,8);
	push(&head2,6);
	push(&head2,4);
	push(&head2,2);
	print(head2);
	intersection(head1,head2);
}