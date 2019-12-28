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

int getCount(node* head){
	int count = 0;
	node* tmp = head;
	if(head==NULL)
		return 0;
	do{
		count++;
		tmp=tmp->next;
	}while(tmp!=head);
	return count;
}

void splitHalf(node* head){
	if(head==NULL || head->next==head)
		return;
	node* tmp1 = head;
	node* head1 = head , *head2 = NULL;

	int len = getCount(head);
	int half2 = len/2;
	int half1 = len - half2;

	for(int i = 0; i < half2; i++){
		tmp1 = tmp1->next;
	}

	node* tmp2 = tmp1->next;
	tmp1->next = head;
	head2 = tmp2;

	while(tmp2->next!=head)
		tmp2=tmp2->next;
	tmp2->next = head2;

	printCircularll(head1);
	printCircularll(head2);
}

int main(){
	node* cll = createCircularll(13);
	printCircularll(cll);
	splitHalf(cll);
	return 0;
}