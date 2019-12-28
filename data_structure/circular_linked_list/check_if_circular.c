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

void checkIfCircular(node* head){
	node* tmp = head;
	do{
		tmp=tmp->next;
	}while(tmp!=head && tmp!=NULL);
	if(tmp==head)
		printf("is circular\n");
	else 
		printf("not circular\n");
}

int main(){
	node* cll = createCircularll(10);
	printCircularll(cll);
	checkIfCircular(cll);
	node* sll = createSinglyll(10);
	printSinglyll(sll);	
	checkIfCircular(sll);
	return 0;
}