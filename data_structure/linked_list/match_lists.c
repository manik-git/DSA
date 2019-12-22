/*
Given a singly linked list of characters, write a function that 
returns true if the given list is a palindrome, 
else false.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}node;

int countnodes(node* n){
	int count = 0;
	while(n!=NULL){
		count++;
		n=n->next;
	}
	return count;
}

/*
	1. if length unequal then mismatch
	2. check node by node 

	OR

	1. check node by node till any one reaches null
	2. check if both reached null meaning both empty then match else mismatch
*/
void match(node* n1, node* n2){
	if(countnodes(n1)!=countnodes(n2)){
		printf("mismatch\n");
		return;
	}
	while(n1!=NULL && n2!=NULL){
		if(n1->data!=n2->data){
			printf("mismatch\n");
			return;
		}
		n1=n1->next;
		n2=n2->next;
	}
	printf("match\n");
}

void push(node** headref, int data){
	node* newnode = (node*)malloc(sizeof(node));
	newnode->data=data;
	newnode->next=*headref;
	*headref=newnode;
}

void print(node* n){
	printf("----\nlinked list:\t");
	while(n!=NULL){
		printf("%d\t", n->data);
		n=n->next;
	}
	printf("\n----\n");
}

void main(){
	node* head1 = NULL;
	push(&head1,5);
	push(&head1,4);
	push(&head1,3);
	push(&head1,2);
	push(&head1,1);

	node* head2 = NULL;
	push(&head2,5);
	push(&head2,4);
	push(&head2,3);
	push(&head2,2);
	push(&head2,5);

	print(head1);
	print(head2);

	match(head1,head2);
}