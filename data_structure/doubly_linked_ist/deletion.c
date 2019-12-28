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
	if(head==NULL)
		return;
	while(head!=NULL){
		printf("%p\t:\t%p\t<-\t%d\t->\t%p\n", (void*)head, (void*)head->prev, head->data, (void*)head->next);
		head=head->next;
	}
	printf("----\n");
}

void delete (dllnode** headref, int key){
	if(*headref == NULL)
		return;
	dllnode* temp = *headref;
	if(temp->data==key){
		*headref = temp->next;
		if(temp->next!=NULL)
			temp->next->prev = NULL;
		free(temp);
		printf("node deleted : %d\n", key);
		return;
	}
	while(temp!=NULL && temp->data!=key)
		temp=temp->next;
	if(temp==NULL){
		printf("node not found\n");
		return;
	}
	temp->prev->next=temp->next;
	if(temp->next!=NULL)
		temp->next->prev=temp->prev;
	free(temp);
	printf("node deleted : %d\n", key);
}

void deletePtr(dllnode** headref, dllnode* del){
	if(*headref == NULL || del == NULL)
		return;
	if(del->prev!=NULL)
		del->prev->next = del->next;
	if(del->next!=NULL)
		del->next->prev = del->prev;
	if(*headref==del)
		*headref=del->next;
	free(del);
}

int main(){
	dllnode* doubly = createDoublyll(5);
	printDoublyll(doubly);
	delete(&doubly, 0);
	delete(&doubly, 2);
	delete(&doubly, 4);
	delete(&doubly, 5);
	printDoublyll(doubly);
	delete(&doubly, 3);
	printDoublyll(doubly);
	delete(&doubly, 1);
	printDoublyll(doubly);
	
	doubly = createDoublyll(5);
	printDoublyll(doubly);
	deletePtr(&doubly, doubly);
	printDoublyll(doubly);
	deletePtr(&doubly, doubly->next->next->next);
	printDoublyll(doubly);
	return 0;
}