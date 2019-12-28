/*
void swapKth(struct Node **head_ref, int k) 
{ 
    // Count nodes in linked list 
    int n = countNodes(*head_ref); 
  
    // Check if k is valid 
    if (n < k)  return; 
  
    // If x (kth node from start) and y(kth node from end) are same 
    if (2*k - 1 == n) return; 
  
    // Find the kth node from beginning of linked list. We also find 
    // previous of kth node because we need to update next pointer of 
    // the previous. 
    Node *x = *head_ref; 
    Node *x_prev = NULL; 
    for (int i = 1; i < k; i++) 
    { 
        x_prev = x; 
        x = x->next; 
    } 
  
    // Similarly, find the kth node from end and its previous. kth node 
    // from end is (n-k+1)th node from beginning 
    Node *y = *head_ref; 
    Node *y_prev = NULL; 
    for (int i = 1; i < n-k+1; i++) 
    { 
        y_prev = y; 
        y = y->next; 
    } 
  
    // If x_prev exists, then new next of it will be y. Consider the case 
    // when y->next is x, in this case, x_prev and y are same. So the statement 
    // "x_prev->next = y" creates a self loop. This self loop will be broken 
    // when we change y->next. 
    if (x_prev) 
        x_prev->next = y; 
  
    // Same thing applies to y_prev 
    if (y_prev) 
        y_prev->next = x; 
  
    // Swap next pointers of x and y. These statements also break self 
    // loop if x->next is y or y->next is x 
    Node *temp = x->next; 
    x->next = y->next; 
    y->next = temp; 
  
    // Change head pointers when k is 1 or n 
    if (k == 1) 
        *head_ref = y; 
    if (k == n) 
        *head_ref = x; 
} 
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

void swap(dllnode* key1, dllnode* key2){
	dllnode* temp;
	
	key1->prev->next = key2;
	key1->next->prev = key2;
	key2->prev->next = key1;
	key2->next->prev = key1;

	temp = key1->next;
	key1->next = key2->next;
	key2->next = temp;
	
	temp = key1->prev;
	key1->prev = key2->prev;
	key2->prev = temp;
}

int getCount(dllnode* head){
	int count = 0;
	while(head){
		count++;
		head=head->next;
	}
	return count;
}

void swapKth(dllnode** headref, int k){
	int count = 0;
	dllnode* temp = *headref,  *key1 = NULL, *key2 = NULL;
	while(temp!=NULL && count!=k-1){
		count++;
		temp=temp->next;
	}
	if(temp==NULL)
		return;
	key1=temp;
	printf("key1:%p\n",(void*)key1);
	count=0;
	temp=*headref;
	printf("len : %d\n",getCount(*headref));
	while(temp!=NULL && count!=getCount(*headref)-k){
		count++;
		temp=temp->next;
	}
	if(temp==NULL)
		return;
	key2=temp;
	printf("key2:%p\n",(void*)key2);
	swap(key1, key2);
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
	swapKth(&doubly, 2);
	printDoublyll(doubly);
	return 0;
}