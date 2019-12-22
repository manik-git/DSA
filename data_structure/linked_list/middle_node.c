/*
Given a singly linked list, find middle of the linked list. 
For example, if given linked list is 1->2->3->4->5 then 
output should be 3.

If there are even nodes, then there would be two middle nodes, 
we need to print second middle element. 
For example, if given linked list is 1->2->3->4->5->6 then 
output should be 4.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}node;

int countNodes(node* n){
	int count = 0;

	while(n!=NULL){
		count++;
		n=n->next;
	}

	return count;
}

void getMiddle(node* n){
	int len = countNodes(n);
	printf("no. of nodes : %d\n", len);
	int mid = len/2 + 1;
	printf("middle node position : %d\n", mid);

	for(int i=0; n!=NULL && i!=mid; i++)
		n=n->next;

	if(n==NULL){
		printf("list is empty\n");
		return;
	}

	printf("middle[%d] node is %d\n", mid, n->data);
}

void push(node** headref, int data){
	node* newnode = (node*)malloc(sizeof(node));
	newnode->data=data;
	newnode->next=*headref;
	*headref=newnode;
}

void main(){
	node* head = NULL;
	push(&head,10);
	push(&head,12);
	push(&head,13);
	push(&head,15);
	push(&head,14);
	push(&head,16);
	push(&head,17);
	push(&head,18);
	push(&head,19);
	push(&head,23);
	push(&head,20);
	push(&head,34);
	push(&head,1);
	push(&head,80);

	getMiddle(head);

}