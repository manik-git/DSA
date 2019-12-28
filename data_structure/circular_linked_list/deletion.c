/*
void deleteNode(struct Node* head, int key) 
{ 
    if (head == NULL) 
        return; 
  
    // Find the required node 
    struct Node *curr = head, *prev; 
    while (curr->data != key) { 
        if (curr->next == head) { 
            printf("\nGiven node is not found"
                   " in the list!!!"); 
            break; 
        } 
  
        prev = curr; 
        curr = curr->next; 
    } 
  
    // Check if node is only node 
    if (curr->next == head) { 
        head = NULL; 
        free(curr); 
        return; 
    } 
  
    // If more than one node, check if 
    // it is first node 
    if (curr == head) { 
        prev = head; 
        while (prev->next != head) 
            prev = prev->next; 
        head = curr->next; 
        prev->next = head; 
        free(curr); 
    } 
  
    // check if node is last node 
    else if (curr->next == head) { 
        prev->next = head; 
        free(curr); 
    } 
    else { 
        prev->next = curr->next; 
        free(curr); 
    } 
} 
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}node;

void delete(node** headref, int key){
	if(*headref==NULL)
		return;
	node* prev = NULL, *curr = *headref;
	do{
		prev=curr;
		curr=curr->next;
	}while(curr!=*headref && curr->data!=key);

	if(curr->next==curr){
		*headref = NULL;
		free(curr);
		return;
	}

	if(curr==*headref && curr->data == key){
		prev=*headref;
		do{
			prev=prev->next;
		}while(prev->next!=*headref);
		*headref = curr->next;
		prev->next=*headref;
		free(curr);
		return;
	} else if(curr==*headref && curr->data != key){
		printf("key not found\n");
		return;
	}

	if(curr->next==*headref){
		prev->next=*headref;
		free(curr);
		return;
	}

	prev->next = curr->next;
	free(curr);
}

void push (node** headref, int data){
	node* newnode = (node*)malloc(sizeof(node));
	newnode->data = data;
	newnode->next = newnode;
	node* temp = *headref;
	if(*headref!=NULL){
		while(temp->next!=*headref)
			temp=temp->next;
		temp->next=newnode;
		newnode->next=*headref;
		*headref = newnode;
	} else {
		*headref = newnode;
	}
}

void print(node* head){
	node* temp = head;
	printf("----\nhead : %p\n", (void *)head);
	if(head==NULL)
		return;
	do{
		printf("%p\t:\t%d\t->\t%p\n", (void*)temp, temp->data, (void*)temp->next);
		temp=temp->next;
	}while(temp!=head);
	printf("----\n");
}
int main(){
	node* head = NULL;
	delete(&head,3);
	print(head);
	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);
	print(head);
	delete(&head,3);
	print(head);
	delete(&head,1);
	print(head);
	delete(&head,5);
	print(head);
	delete(&head,100);
	print(head);
	return 0;
}