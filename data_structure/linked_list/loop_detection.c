/*
Given a linked list, check if the linked list has loop or not.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	int visited;
	struct node* next;
}node;

int countnodes(node* n){
	int count=0;
	while(n!=NULL){
		n=n->next;
		count++;
	}
	return count;
}

void detect(node* n){

	while(n!=NULL){
		if(n->visited==0){
			n->visited=1;
			n=n->next;
		} else {
			printf("loop detected\n");
			return;
		}
	}
	printf("no loop detected\n");
}

void push(node** headref, int data){
	node* newnode = (node*)malloc(sizeof(node));
	newnode->data=data;
	newnode->next=*headref;
	*headref=newnode;
}

void main(){
	node* head = NULL;

	push(&head,5);
	push(&head,4);
	push(&head,3);
	push(&head,2);
	push(&head,1);

	detect(head);

	head->next->next->next->next->next=head->next->next;

	detect(head);

	head->next->next->next->next->next = NULL;

	detect(head); // fails here since all visited flags are set already

}