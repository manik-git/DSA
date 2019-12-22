/*
This is the fastest method and has been described below:

-Traverse linked list using two pointers. 
-Move one pointer(slow_p) by one and another pointer(fast_p) by two. 
-If these pointers meet at the same node then there is a loop. 
 If pointers do not meet then linked list doesn’t have a loop
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

	detect(head);
}