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

void deleteAt(dllnode** headref, int pos){
	dllnode* temp = *headref;
	int count = 1;
	while(temp!=NULL && count!=pos){
		count++;
		temp=temp->next;
	}
	if(temp==NULL)
		return;
	if(temp->prev!=NULL)
		temp->prev->next=temp->next;
	else
		*headref=temp->next;
	if(temp->next!=NULL)
		temp->next->prev=temp->prev;
	printf("deleting : %d\n", temp->data);
	free(temp);
}

int main(){
	dllnode* doubly = createDoublyll(10);
	printDoublyll(doubly);
	deleteAt(&doubly, 5);
	deleteAt(&doubly, 1);
	deleteAt(&doubly, 8);
	printDoublyll(doubly);
	return 0;
}