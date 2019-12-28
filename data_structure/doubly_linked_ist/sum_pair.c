/*
// Function to find pair whose sum equal to given value x. 
void pairSum(struct Node *head, int x) 
{ 
    // Set two pointers, first to the beginning of DLL 
    // and second to the end of DLL. 
    struct Node *first = head; 
    struct Node *second = head; 
    while (second->next != NULL) 
         second = second->next; 
  
    // To track if we find a pair or not 
    bool found = false; 
  
    // The loop terminates when either of two pointers 
    // become NULL, or they cross each other (second->next 
    // == first), or they become same (first == second) 
    while (first != NULL && second != NULL && 
           first != second && second->next != first) 
    { 
         // pair found 
         if ((first->data + second->data) == x) 
         { 
              found = true; 
              cout << "(" << first->data<< ", "
                   << second->data << ")" << endl; 
  
              // move first in forward direction 
              first = first->next; 
  
              // move second in backward direction 
              second = second->prev; 
          } 
          else
          { 
              if ((first->data + second->data) < x) 
                 first = first->next; 
              else
                 second = second->prev; 
          } 
      } 
  
      // if pair is not present 
      if (found == false) 
           cout << "No pair found"; 
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

void findSumPair(dllnode* head, int sum){
    dllnode* temp1 = head, *temp2 = head;
    while(temp1!=NULL){
        temp2=temp1->next;
        while(temp2!=NULL){
            if(temp2->data==sum-temp1->data){
                printf("(%d, %d)\n", temp1->data, temp2->data);
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
    findSumPair(doubly, 7);
    return 0;
}