/*
Write a function detectAndCountLoop() that checks whether 
a given Linked List contains loop and 
if loop is present then returns count of nodes in loop. 
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}node;

void detect(node* n){

	node* slow_p = n;
	node* fast_p = n;

	while(slow_p!=NULL && fast_p!=NULL && fast_p->next!=NULL){
		slow_p=slow_p->next;
		fast_p=fast_p->next->next;
		if(slow_p==fast_p){
			printf("loop detected\n");
			node* loop_start = slow_p;
			int loop_count = 0;
			do{
				loop_count++;
				slow_p=slow_p->next;
			}while(slow_p!=loop_start);
			printf("nodes in a loop: %d\n----\n", loop_count);
			return;
		}
	}
	printf("no loop detected\n----\n");
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

	head->next->next->next->next->next=head;

	detect(head);

	head->next->next->next->next->next=head->next;
	
	detect(head);

	head->next->next->next->next->next=head->next->next;
	
	detect(head);

	head->next->next->next->next->next=head->next->next->next->next;
	
	detect(head);
}