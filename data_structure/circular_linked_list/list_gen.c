#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}node;

node* createNode(int data){
	node* newnode = (node*)malloc(sizeof(node));
	newnode->data = data;
	newnode->next = NULL;
	// printf("node created\t#\t%p\t:\t%d\t->\t%p\n",(void*)newnode, newnode->data, (void*)newnode->next);
	return newnode;
}

node* createSinglyll(int n){
	node* head = createNode(0);
	node* tmp = head;
	for(int i = 1; i<n; i++){
		tmp->next = createNode(i);
		tmp=tmp->next;
	}
	return head;
}

void printSinglyll(node* head){
	printf("----\nhead\t:\t%p\n", (void*)head);
	while(head!=NULL){
		printf("%p\t:\t%d\t->\t%p\n", (void*)head, head->data, (void*)head->next);
		head=head->next;
	}
	printf("----\n");
}

node* createCircularll(int n){
	node* head = createNode(0);
	node* tmp = head;
	for(int i = 1; i < n; i++){
		tmp->next = createNode(i);
		tmp=tmp->next;
	}
	tmp->next = head;
	return head;
}

void printCircularll(node* h){
	node* head = h;
	printf("----\nhead\t:\t%p\n", (void*)head);
	do{
		printf("%p\t:\t%d\t->\t%p\n", (void*)head, head->data, (void*)head->next);
		head=head->next;
	}while(head!=h);
	printf("----\n");	
}

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

int main(){
	node* singly = createSinglyll(10);
	printSinglyll(singly);
	node* circular = createCircularll(10);
	printCircularll(circular);
	dllnode* doubly = createDoublyll(10);
	printDoublyll(doubly);
	return 0;
}