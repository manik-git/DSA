/*
https://www.geeksforgeeks.org/pairwise-swap-elements-of-a-given-linked-list/
the solution in website swaps data and not nodes.. the solution below swaps nodes

Given a singly linked list, write a function to swap elements pairwise.
For example, if the linked list is 1->2->3->4->5
then the function should change it to 2->1->4->3->5
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}node;

void swap(node** headref, int x, int y){
	if(x==y)
		return;
	node* currX = *headref, *prevX = NULL;
	while(currX && currX->data!=x){
		prevX = currX;
		currX=currX->next;
	}
	node* currY = *headref, *prevY = NULL;
	while(currY && currY->data!=y){
		prevY = currY;
		currY=currY->next;
	}
	if(currX==NULL || currY==NULL){
		printf("item not found\n");
		return;
	}
	if(prevX!=NULL){
		prevX->next=currY;
	} else {
		*headref=currY;
	}
	if(prevY!=NULL){
		prevY->next=currX;
	} else {
		*headref=currX;
	}
	node* tmp = currX->next;
	currX->next = currY->next;
	currY->next = tmp;
}

void swapPairwise(node** headref){
	node* node1 = *headref;	
	while(node1!=NULL && node1->next!=NULL){
		printf("node1: %d\tnode1->next: %d\n",node1->data,node1->next->data);
		swap(&*headref,node1->data,node1->next->data);

		if(node1->next!=NULL) // just for following statement
			printf("after swap\nnode1: %d\tnode1->next: %d\n\n",node1->data,node1->next->data); // doesn't work without condition since at last node no data in next node(NULL)
		else
			printf("afterswap\nnode1: %d\tnode1->next: NULL\n\n",node1->data);

		node1=node1->next; // since the node are already swapped pointer only needs to jump once
	}
}

void push(node** headref, int data){
	node* newnode = (node*)malloc(sizeof(node));
	newnode->data=data;
	newnode->next=*headref;
	*headref=newnode;
}

void print(node* head){
	printf("----\n");
	while(head!=NULL){
		printf("%d\t",head->data);
		head=head->next;
	}
	printf("\n----\n");
}

void main(){
	node* head = NULL;
	push(&head,6);
	push(&head,5);
	push(&head,4);
	push(&head,3);
	push(&head,2);
	push(&head,1);
	print(head);
	swapPairwise(&head);
	print(head);
}