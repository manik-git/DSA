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

void push(dllnode** headref, dllnode* newnode){
	newnode->prev=NULL;
	newnode->next=*headref;
	if(*headref!=NULL)
		(*headref)->prev=newnode;
	*headref=newnode;
}

dllnode* reverseNnodes(dllnode* head, int n){
	dllnode* curr = head, *next = NULL, *newhead = NULL;
	int count = 0;
	while(curr!=NULL && count < n){
		next = curr->next;
		push(&newhead, curr);
		curr=next;
		count++;
	}
	if(next!=NULL){
		head->next=reverseNnodes(next,n);
		head->next->prev=head;
	}
	return newhead;
}

void printDoublyll(dllnode* head){
	printf("----\nhead\t:\t%p\n", (void*)head);
	while(head!=NULL){
		printf("%p\t:\t%p\t<-\t%d\t->\t%p\n", (void*)head, (void*)head->prev, head->data, (void*)head->next);
		head=head->next;
	}
	printf("----\n");
}

int main(){
	dllnode* doubly = createDoublyll(10);
	printDoublyll(doubly);
	printDoublyll(reverseNnodes(doubly, 4));
	return 0;
}