/*
Given a singly linked list and a key, 
count number of occurrences of given key in linked list. 

For example, if given linked list is 1->2->1->2->1->3->1 
and given key is 1, 
then output should be 4.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}node;

void countkey (node* n, int key){
	int count = 0;
	while(n!=NULL){
		if(n->data == key)
			count++;
		n=n->next;
	}
	printf("item[%d] occures %d times\n", key, count);
}

void push(node** headref, int data){
	node* newnode = (node*)malloc(sizeof(node));
	newnode->data=data;
	newnode->next=*headref;
	*headref=newnode;
}

void main(){
	node* head = NULL;
	push(&head,80);
	push(&head,12);
	push(&head,80);
	push(&head,15);
	push(&head,14);
	push(&head,16);
	push(&head,17);
	push(&head,80);
	push(&head,19);
	push(&head,23);
	push(&head,80);
	push(&head,34);
	push(&head,1);
	push(&head,80);

	countkey(head, 80);
	countkey(head, 17);
	countkey(head, 100);

}