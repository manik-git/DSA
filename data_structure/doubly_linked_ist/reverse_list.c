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

void reverseList(dllnode** headref){
	dllnode* head = *headref , *temp = NULL;
	while(head!=NULL){
		// printf("%p\t:\t%p\t<-\t%d\t->\t%p\n", (void*)head, (void*)head->prev, head->data, (void*)head->next);
		temp=head->prev; // store prev in temp first so that it stays a step behind 
						 // from head and could be used later for headref.. 
						 // if temp stores next it reaches null at the last node and can not be used for headref
		head->prev=head->next;
		head->next=temp;
		head=head->prev;
		// printf("%p\t:\t%p\t<-\t%d\t->\t%p\n", (void*)head, (void*)head->prev, head->data, (void*)head->next);
	}
	if(temp != NULL)
		*headref=temp->prev; // since temp next is temps prev
}

int main(){
	dllnode* doubly = createDoublyll(5);
	printDoublyll(doubly);
	reverseList(&doubly);
	printDoublyll(doubly);
	return 0;
}