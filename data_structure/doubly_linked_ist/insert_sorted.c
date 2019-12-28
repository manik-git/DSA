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

void insertSorted(dllnode** headref, int data){
	dllnode* newnode = createDllnode(data);
	dllnode* temp = *headref, *prevptr = NULL;
	if(data < temp->data){
		newnode->next = *headref;
		*headref = newnode;
		return;
	}
	while(temp!=NULL && temp->data <= data){
		prevptr=temp;
		temp=temp->next;
	}
	newnode->next=temp;
	newnode->prev=prevptr;
	prevptr->next=newnode;
	if(temp!=NULL)
		temp->prev=newnode;
}

int main(){
	dllnode* doubly = createDoublyll(2);
	printDoublyll(doubly);
	insertSorted(&doubly, 5);
	insertSorted(&doubly, 3);
	insertSorted(&doubly, 4);
	insertSorted(&doubly, 2);
	insertSorted(&doubly, 6);
	printDoublyll(doubly);
	return 0;
}