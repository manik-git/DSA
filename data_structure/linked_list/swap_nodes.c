/*
Given a linked list and two keys in it, swap nodes for two given keys. 
Nodes should be swapped by changing links. 
Swapping data of nodes may be expensive in many situations when data contains many fields.
It may be assumed that all keys in linked list are distinct.

Examples:

Input:  10->15->12->13->20->14,  x = 12, y = 20
Output: 10->15->20->13->12->14

Input:  10->15->12->13->20->14,  x = 10, y = 20
Output: 20->15->12->13->10->14

Input:  10->15->12->13->20->14,  x = 12, y = 13
Output: 10->15->13->12->20->14

This may look a simple problem, but is interesting question as it has following cases to be handled.
1) x and y may or may not be adjacent.
2) Either x or y may be a head node.
3) Either x or y may be last node.
4) x and/or y may not be present in linked list.
*/


#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}node;

void swap(node** headref, int x, int y){

	if( x == y )
		return;
	
	node* currX = *headref, *prevX = NULL;
	node* currY = *headref, *prevY = NULL;

	while(currX!= NULL && currX->data!=x){
		prevX=currX;
		currX=currX->next;
	}
	while(currY!=NULL && currY->data!=y){
		prevY=currY;
		currY=currY->next;
	}

	if(currX==NULL || currY==NULL){
		printf("item not found\n");
		return;
	}

	if(prevX!=NULL){ // x in not head node
		prevX->next=currY;
	} else {
		*headref=currY;
	}

	if(prevY!=NULL){
		prevY->next=currX;
	} else {
		*headref=currX;
	}

	node* temp = currX->next;
	currX->next = currY->next;
	currY->next = temp;
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
	push(&head,1);
	push(&head,2);
	push(&head,3);
	push(&head,4);
	push(&head,5);
	push(&head,6);
	push(&head,7);
	push(&head,8);
	push(&head,9);
	push(&head,10);

	print(head);

	swap(&head, 1, 10);

	print(head);

	swap(&head, 10, 1);

	print(head);

	swap(&head, 1, 6);

	print(head);

	swap(&head, 5, 6);

	print(head);

	swap(&head, 1, 2);

	print(head);
}