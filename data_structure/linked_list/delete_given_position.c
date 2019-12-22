// deleting a node at a given position

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}node;

void deleteAt(node** headref, int pos){
	if(*headref==NULL){
		printf("list empty\n");
		return;
	}

	node* tmp = *headref;

	if(pos == 0){
		*headref = tmp->next;
		free(tmp);
		printf("pos[%d] deleted\n", pos);
		return;
	}

	for(int i = 0; tmp!= NULL && i < pos-1; i++)
		tmp=tmp->next;

	if(tmp==NULL || tmp->next==NULL){
		printf("pos[%d] not found\n", pos);
		return;
	}

	node* nxt = tmp->next->next;

	free(tmp->next);

	tmp->next = nxt;

	printf("pos[%d] deleted\n", pos);
}

void push(node** headref, int data){
	node* newnode = (node*)malloc(sizeof(node));

	newnode->data=data;
	newnode->next=*headref;
	*headref=newnode;
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
	push(&head,4);
	push(&head,3);
	push(&head,2);
	push(&head,1);
	print(head);
	deleteAt(&head, 0);
	print(head);
	deleteAt(&head, 1);
	print(head);
	deleteAt(&head, 2);
	print(head);
	deleteAt(&head, 3);
	print(head);
}