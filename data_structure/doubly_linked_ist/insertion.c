#include <stdio.h>
#include <stdlib.h>

typedef struct dllnode{
	int data;
	struct dllnode* prev;
	struct dllnode* next;
}dllnode;

dllnode* createDllnode(int data){
	dllnode* newnode = (dllnode*)malloc(sizeof(dllnode));
	newnode->data = data;
	newnode->prev = NULL;
	newnode->next = NULL;
	return newnode;
}

dllnode* createDoublyll(int n){
	dllnode* head = createDllnode(0);
	dllnode* prevptr = head, *currptr=NULL;
	for(int i = 1; i < n; i++){
		currptr = createDllnode(i);
		prevptr->next = currptr;
		currptr->prev = prevptr;
		prevptr = currptr;
	}
	return head;
}
 
void printDoublyll(dllnode* head){
	printf("----\nhead\t:\t%p\n", (void*)head);
	while(head!=NULL){
		printf("%p\t:\t%p\t<-\t%d\t->\t%p\n", (void*)head, (void*)head->prev, head->data, (void*)head->next);
		head=head->next;
	}
	printf("----\n");
}

void insertStart (dllnode** headref, int data){
	dllnode* newnode = createDllnode(data);
	(*headref)->prev = newnode;
	newnode->next = *headref;
	*headref = newnode;	
}

void insertLast ( dllnode** headref, int data){
	dllnode* newnode = createDllnode(data);
	dllnode* temp = *headref;
	while(temp->next!=NULL)
		temp=temp->next;
	newnode->prev = temp;
	temp->next = newnode;
}

void insertAfter ( dllnode** headref, int key, int data){
	dllnode* newnode = createDllnode(data);
	dllnode* temp = *headref;
	while(temp!=NULL && temp->data!=key)
		temp=temp->next;
	if(temp==NULL){
		printf("item not found\n");
		return;
	}
	newnode->next = temp->next;
	temp->next->prev = newnode;
	temp->next = newnode;
	newnode->prev = temp;
}

void insertBefore(dllnode** headref, int key, int data){
	dllnode* newnode = createDllnode(data);
	dllnode* temp = *headref;
	while(temp!=NULL && temp->data!=key)
		temp=temp->next;
	if(temp==NULL){
		printf("item not found\n");
		return;
	}
	temp->prev->next=newnode;
	newnode->prev=temp->prev;
	newnode->next=temp;
	temp->prev=newnode;
}

int main(){
	dllnode* doubly = createDoublyll(5);
	printDoublyll(doubly);
	insertStart(&doubly, -1);
	printDoublyll(doubly);
	insertLast(&doubly, 100);
	printDoublyll(doubly);
	insertAfter(&doubly, 101, 50);
	printDoublyll(doubly);
	insertAfter(&doubly, -1, 50);
	printDoublyll(doubly);
	insertBefore(&doubly, 101, 50);
	printDoublyll(doubly);
	insertBefore(&doubly, 50, 25);
	printDoublyll(doubly);
	return 0;
}