// delete a given node in a linked list .

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}node;

void delete(node** headref, int item){
	if(*headref==NULL){
		printf("list is empty\n");
		return;
	}

	node* tmp = *headref, *prev;

	if(tmp->data==item){
		*headref=tmp->next;
		free(tmp);
		return;
	}

	while(tmp != NULL && tmp->data!=item){
		prev=tmp;
		tmp=tmp->next;
	}

	if(tmp==NULL){
		printf("item[%d] not found\n", item);
		return;
	}

	prev->next=tmp->next;
	free(tmp);

	printf("item[%d] deleted\n", item);
}

void push(node** headref, int data){
	node* newnode = (node*)malloc(sizeof(node));
	newnode->data=data;
	newnode->next=*headref;
	*headref=newnode;
}

void print(node* headref){
	printf("----\nlinked list:\t");
	while(headref!=NULL){
		printf("%d\t",headref->data);
		headref=headref->next;
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
	delete(&head,3);
	delete(&head,6);
	print(head);
}