/*
Write a removeDuplicates() function which takes a list 
and deletes any duplicate nodes from the list. 
The list is not sorted.
For example if the linked list is 12->11->12->21->41->43->21 
then removeDuplicates() should convert the list to 12->11->21->41->43.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}node;

void push(node** headref, int data){
	node* newnode = (node*)malloc(sizeof(node));
	newnode->data=data;
	newnode->next=*headref;
	*headref=newnode;
}

/*

void removeDuplicates(struct Node *start) 
{ 
    struct Node *ptr1, *ptr2, *dup; 
    ptr1 = start; 
  
    while (ptr1 != NULL && ptr1->next != NULL) 
    { 
        ptr2 = ptr1; 
  
        while (ptr2->next != NULL) 
        { 
            if (ptr1->data == ptr2->next->data) 
            { 
                dup = ptr2->next; 
                ptr2->next = ptr2->next->next; 
                delete(dup); 
            } 
            else
                ptr2 = ptr2->next; 
        } 
        ptr1 = ptr1->next; 
    } 
} 
*/

void removeDuplicates(node** headref){
	node* tmp1 = *headref, *tmp2 = NULL, *prev=NULL, *nxt=NULL;;
	while(tmp1->next!=NULL){
		tmp2=tmp1->next;
		prev=tmp1;
		while(tmp2!=NULL){
			if(tmp2->data==tmp1->data){
				prev->next=tmp2->next;
				nxt=tmp2->next;
				free(tmp2);
				tmp2=nxt;
			} else {
				prev=tmp2;
				tmp2=tmp2->next;
			}
		}
		tmp1=tmp1->next;
	}
}

void print(node* n){
	printf("----\nlinked list:\t");
	while(n!=NULL){
		printf("%d\t",n->data);
		n=n->next;
	}
	printf("\n----\n");
}

void main(){
	node* head = NULL;
	push(&head,5);
	push(&head,10);
	push(&head,9);
	push(&head,8);
	push(&head,6);
	push(&head,6);
	push(&head,7);
	push(&head,5);
	push(&head,6);
	push(&head,5);
	print(head);
	removeDuplicates(&head);
	print(head);
}