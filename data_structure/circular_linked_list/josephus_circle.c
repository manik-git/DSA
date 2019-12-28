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
	node* head = createNode(1);
	node* tmp = head;
	for(int i = 2; i <= n; i++){
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
	do{
		count++;
		tmp=tmp->next;
	}while(tmp!=head);
	return count;
}

int josephusCircle(node* head, int m){
	int len = getCount(head);
	node* tmp = head, *prev = NULL;;
	while(tmp->next!=tmp){
		for(int i = 1; i != m; i++){
			prev = tmp;
			tmp=tmp->next;
		}
		printf("shot:\t%d\n",tmp->data);
		prev->next=tmp->next;
		tmp=tmp->next;
		printCircularll(tmp);
	}

	return tmp->data;
}

int main(){
	int n = 5, m = 3;
	node* circular = createCircularll(n);
	printCircularll(circular);
	printf("n\t=\t%d,\tm\t=\t%d\nposition\t=\t%d\n", n, m, josephusCircle(circular,m));
	return 0;
}