#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}node;

void count(node* head){
	int count = 0;
	node* tmp = head;
	do{
		tmp=tmp->next;
		count++;
	}while(tmp!=head);
	printf("no. of nodes\t:\t%d\n", count);
}

void push(node** headref, int data){
	node* newnode = (node*)malloc(sizeof(node));
	newnode->data = data;
	newnode->next = newnode;
	node* tmp = *headref;
	if(*headref!=NULL){
		while(tmp->next!=*headref)
			tmp=tmp->next;
		tmp->next = newnode;
		newnode->next=*headref;
	} else {
		*headref = newnode;
	}
}

void print(node* head){
	printf("----\nhead : %p\n", (void *)head);
	if(head==NULL)
		return;
	node* n = head;
	do{
		printf("%p\t:\t%d\t->\t%p\n", (void*)n, n->data, (void*)n->next);
		n=n->next;
	}while(n!=head);
	printf("----\n");
}

int main(){
	node* head = NULL;
	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);
	print(head);	
	count(head);
	return 0;
}