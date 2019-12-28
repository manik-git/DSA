#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
}node;

void insertFirst(node** headref, int data){
	node* newnode = (node*)malloc(sizeof(node));
	newnode->data = data;
	newnode->next = *headref;
	node* temp = *headref;
//	printf("1. newnode: %p, temp: %p, head: %p\n", (void*)newnode, (void*)temp, (void*)*headref);
	if(*headref!=NULL){
		while(temp->next!=*headref)
			temp=temp->next;
		// printf("2. newnode: %p, newnode->next: %p\n   temp: %p, temp->next: %p\n   head: %p\n", (void*)newnode, (void*)newnode->next, (void *)temp, (void*)temp->next, (void*)*headref);
		temp->next=newnode;
		// printf("3. newnode: %p, newnode->next: %p\n   temp: %p, temp->next: %p\n   head: %p\n", (void*)newnode, (void*)newnode->next, (void *)temp, (void*)temp->next, (void*)*headref);
	} else {
		newnode->next=newnode;
	}
	*headref = newnode;
	// printf("4. newnode: %p, temp: %p, head: %p\n", (void*)newnode, (void*)temp, (void*)*headref);
}

void insertAfter(node** headref, int key, int data){

	node* newnode = (node*)malloc(sizeof(node));
	newnode->data=data;
	newnode->next=newnode;
	node* temp = *headref;
	if(*headref!=NULL){
		do{
			temp=temp->next;
		}while(temp->data!=key && temp->next!=*headref);
		if(temp->next==*headref){
			printf("key not found\n");
			return;
		}
		newnode->next=temp->next;
		temp->next=newnode;
	} else {
		*headref = newnode;
	}
}

void insertLast(node** headref, int data){
	node* newnode = (node*)malloc(sizeof(node));
	newnode->data = data;
	newnode->next = *headref;
	node* temp = *headref;

	if(*headref!=NULL){
		while(temp->next!=*headref)
			temp=temp->next;
		temp->next = newnode;
	} else {
		newnode->next = newnode;
	}
}

void print(node* head){
	node* n = head;
	printf("----\nhead : %p\n", (void *)head);
	if(!head)
		return;
	do{
		printf("%p : %d -> %p\n", (void *)n, n->data, (void *)n->next);
		n=n->next;
	}while(n!=head);
	printf("----\n");
}

int main(){
	node* head = NULL;
	print(head);
	insertFirst(&head,50);
	print(head);
	insertFirst(&head,10);
	print(head);
	insertFirst(&head,0);
	print(head);
	insertFirst(&head,-10);
	print(head);
	insertAfter(&head, 10, 25);
	print(head);
	insertAfter(&head, 50, 75);
	print(head);
	insertLast(&head, 100);
	print(head);
	insertAfter(&head, 5, 75);
	return 0;
}