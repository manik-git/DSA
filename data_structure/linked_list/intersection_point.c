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

void pointOfIntersection(node* h1, node* h2){
	node* head2 = h2;
	while(h1 && h2){
		while(h2){
			if(h2->data == h1->data){
				printf("pointOfIntersection : %d\n", h1->data);
				return;
			}
			h2=h2->next;
		}
		h1=h1->next;
		h2 = head2;
	}
	printf("pointOfIntersection : NONE\n");
}

void main(){
	node* head1 = NULL, *head2 = NULL;
	push(&head1,5);
	push(&head1,4);
	push(&head1,3);
	push(&head1,12);
	push(&head1,1);
	print(head1);
	push(&head2,5);
	push(&head2,12);
	push(&head2,3);
	push(&head2,7);
	push(&head2,11);
	print(head2);
	pointOfIntersection(head1, head2);
}