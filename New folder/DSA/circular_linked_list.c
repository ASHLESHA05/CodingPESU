/*//used where entire list is aseccesd one by onr in a loop.eg.in operating system may use it to switch between operations.
// operation: 1.insertion
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}NODE;
void push(NODE **head,int ele)
{
    NODE *newnode=(NODE*)malloc(sizeof(NODE));
    newnode->data=ele;
    newnode->next=*head;
    if(*head!=NULL){
        NODE *p=*head;
        while( p->next !=*head){
             p=p->next;
        }
        p->next=newnode;
    }
    else{
        newnode->next=newnode;
        *head=newnode;
    }
  

}
int main()
{
  NODE *head=NULL;
  push(&head,10);
  push(&head,20);
  push(&head,20);
  push(&head,30);

}
void deleteNode(NODE **head, int key)
{   
    NODE *curr = head, *prev;
    while (curr->data != key){
        prev = curr;
        curr = curr->next;
    }
    if (curr->next == head){
        head = NULL;
        free(curr);
        return;
    }
    if (curr == head){
        prev = head;
        while (prev->next != head)
            prev = prev->next;
        head = curr->next;
        prev->next = head;
        free(curr);
    }
  
    else if (curr->next == head && curr == head) 
    {
        prev->next = head;
        free(curr);
    }
    else 
    {
        prev->next = curr->next;
        free(curr);
    }
}
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
typedef struct joseph{
    int index;
    struct joseph *next;
}NODE;
void push(NODE **head,int ele)
{
    NODE *newnode=(NODE*)malloc(sizeof(NODE));
    newnode->index=ele;
    newnode->next=*head;
    if(*head!=NULL){
        NODE *p=*head;
        while(p->next !=*head)
            p=p->next;
        p->next=newnode;
    }
    else{
        newnode->next=newnode;
        *head=newnode;
    }
}
void deleteNode(NODE **head, int key)
{   
    NODE *curr = *head, *prev;
    while (curr->index != key){
        prev = curr;
        curr = curr->next;
    }
    if (curr->next == *head){
        *head = NULL;
        free(curr);
        return;
    }
    if (curr== *head){
        prev= *head;
        while (prev->next != *head)
            prev=prev->next;
        *head=curr->next;
        prev->next= *head;
        free(curr);
    }
  
    else if (curr->next == *head && curr == *head) 
    {
        prev->next = *head;
        free(curr);
    }
    else 
    {
        prev->next = curr->next;
        free(curr);
    }
}
void eliminate(NODE **head,int k){
    if((*head)->next == *head)
    {
        printf("%d",0);
    }
    else{
        while((*head)->next != *head){
            deleteNode(head,k);
        }
        printf("%d",(*head)->index);
        
    }
}

int main() {

    int n=5,k=2;
    NODE *head=NULL;
    for(int i=0;i<n;i++)
        push(&head,i);
    eliminate(&head,k);
    return 0;
}
