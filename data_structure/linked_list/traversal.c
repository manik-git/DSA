#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
};

void print(struct node* n){
	while(n!=NULL){
		printf("%d ", n->data);
		n=n->next;
	}
	printf("\n");
}

int main(){

	struct node* head = (struct node*)malloc(sizeof(struct node));
	struct node* second = (struct node*)malloc(sizeof(struct node));
	struct node* third = (struct node*)malloc(sizeof(struct node));

	head->data = 1;
	head->next = second;
	second->data = 2;
	second->next = third;
	third->data = 3;
	third->next = NULL;

	print(head);

	return 0;
}