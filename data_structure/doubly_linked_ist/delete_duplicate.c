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

void insertAfter(dllnode** headref, int key, int data){
	dllnode* newnode = createDllnode(data);
	dllnode* temp = *headref;
	while(temp!=NULL && temp->data!=key)
		temp=temp->next;
	if(temp==NULL)
		return;
	newnode->next=temp->next;
	if(temp->next!=NULL)
		temp->next->prev=newnode;
	newnode->prev=temp;
	temp->next=newnode;
}

void removeDuplicates(dllnode** headref, int key){
	dllnode* temp = *headref;
	while(temp!=NULL && temp->data!=key)
		temp=temp->next;
	if(temp==NULL)
		return;
	temp=temp->next;
	while(temp!=NULL){
		if(temp->data==key){
			temp->prev->next=temp->next;
			if(temp->next!=NULL)
				temp->next->prev=temp->prev;
		}
		temp=temp->next;
	}
}

void removeAllDuplicates(dllnode** headref){
	dllnode* temp1 = *headref, *temp2 = *headref;
	while(temp1!=NULL){
		temp2=temp1->next;
		while(temp2!=NULL){
			if(temp2->data==temp1->data){
				temp2->prev->next=temp2->next;
				if(temp2->next!=NULL)
					temp2->next->prev=temp2->prev;
			}
			temp2=temp2->next;
		}
		temp1=temp1->next;
	}
}

int main(){
	dllnode* doubly = createDoublyll(5);
	printDoublyll(doubly);
	insertAfter(&doubly, 3, 2);
	insertAfter(&doubly, 3, 2);
	insertAfter(&doubly, 3, 2);
	insertAfter(&doubly, 4, 2);
	insertAfter(&doubly, 0, 2);
	insertAfter(&doubly, 2, 2);
	insertAfter(&doubly, 4, 1);
	insertAfter(&doubly, 0, 1);
	insertAfter(&doubly, 2, 1);
	insertAfter(&doubly, 2, 1);
	insertAfter(&doubly, 2, 1);
	insertAfter(&doubly, 4, 0);
	insertAfter(&doubly, 0, 0);
	insertAfter(&doubly, 2, 0);
	insertAfter(&doubly, 2, 0);
	insertAfter(&doubly, 2, 0);
	printDoublyll(doubly);
	// removeDuplicates(&doubly,2);
	// removeDuplicates(&doubly,1);
	removeAllDuplicates(&doubly);
	printDoublyll(doubly);
	return 0;
}