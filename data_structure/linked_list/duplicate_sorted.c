/*
Write a function which takes a list sorted in non-decreasing order 
and deletes any duplicate nodes from the list. 
The list should only be traversed once.
For example if the linked list is 11->11->11->21->43->43->60 
then removeDuplicates() should convert the list to 11->21->43->60.
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

void removeDuplicates(node** headref){
	node* tmp = *headref, *nxt;
	while(tmp->next!=NULL){
		if(tmp->next->data==tmp->data){
			nxt = tmp->next->next;
			free(tmp->next);
			tmp->next=nxt;
		} else {
			tmp=tmp->next;
		}
	}	
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
	push(&head,5);
	push(&head,5);
	push(&head,4);
	push(&head,3);
	push(&head,3);
	push(&head,3);
	push(&head,2);
	push(&head,2);
	push(&head,1);
	print(head);
	removeDuplicates(&head);
	print(head);
}