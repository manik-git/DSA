/*
 we create a push function that adds the given node at 
 the beginning of the given list. We traverse the original list 
 and one by one pass the current node pointer to the push function. 
 This process will reverse the list. Finally return the new head of 
 this reversed list.
*/

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

dllnode* reverse(dllnode* _head){
	dllnode* head = _head, *next, *newhead=NULL;
	while(head!=NULL){
		next=head->next;

		head->prev=NULL;
		head->next=newhead;
		if(newhead!=NULL)
			newhead->prev=head;
		newhead = head;

		head=next;
	}
	printDoublyll(newhead);
	return newhead;
}

int main(){
	dllnode* doubly = createDoublyll(10);
	printDoublyll(doubly);
	printDoublyll(reverse(doubly));
	return 0;
}