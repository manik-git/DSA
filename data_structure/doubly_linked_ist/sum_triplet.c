/*
// function to count triplets in a sorted doubly linked list 
// whose sum is equal to a given value 'x' 
int countTriplets(struct Node* head, int x) 
{ 
    struct Node* ptr1, *ptr2, *ptr3; 
    int count = 0; 
  
    // generate all possible triplets 
    for (ptr1 = head; ptr1 != NULL; ptr1 = ptr1->next) 
        for (ptr2 = ptr1->next; ptr2 != NULL; ptr2 = ptr2->next) 
            for (ptr3 = ptr2->next; ptr3 != NULL; ptr3 = ptr3->next) 
  
                // if elements in the current triplet sum up to 'x' 
                if ((ptr1->data + ptr2->data + ptr3->data) == x) 
  
                    // increment count 
                    count++; 
  
    // required count of triplets 
    return count; 
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
    newnode->prev=temp;
    if(temp->next!=NULL)
        temp->next->prev=newnode;
    temp->next=newnode;
}

void findSumTriplet(dllnode* head, int sum){
    dllnode* temp1 = head, *temp2 = head, *temp3 = head;
    while(temp1!=NULL){
        temp2=temp1->next;
        while(temp2!=NULL){
            if(temp1->data + temp2->data < sum){
                temp3=temp2->next;
                while(temp3!=NULL){
                    if(temp1->data + temp2->data + temp3->data == sum)
                        printf("(%d, %d, %d)\n", temp1->data, temp2->data, temp3->data);
                    temp3=temp3->next;
                }
            }
            temp2=temp2->next;
        }
        temp1=temp1->next;
    }
}

int main(){
    dllnode* doubly = createDoublyll(10);
    insertAfter(&doubly, 9, 10);
    printDoublyll(doubly);
    findSumTriplet(doubly, 27);
    return 0;
}