/*
skip list is a data structure that is used for storing a sorted list of items with a hierarchy of linked list that connects increasingly..
*/
//sparse matrix: more number of 0 than non zero
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int row;
    int column;
    int values;
    struct Node* next;
} NODE;
NODE *create(int row,int column,int values)
{
  NODE *newnode=malloc(sizeof(NODE));
  newnode->row=row;
  newnode->column=column;
  newnode->values=values;
  newnode->next=NULL;
  return newnode;
}
NODE *insert_last(NODE *head,int row,int column,int values)
{
  NODE *newnode=create(row,column,values);
  NODE *p=head;
  if(head==NULL){
    newnode->next=head;
    head=newnode;
    return head;
  }
  while(p->next!=NULL)
    p=p->next;
  p->next=newnode;
  return head;  
}
void display(NODE *head)
{ 
  printf("\n");  
  NODE *p=head;
  while(p!=NULL)
  {
    printf("%d %d %d --->  ",p->row,p->column,p->values);
    p=p->next;
  }

  printf("\n");
}
int main(){
    NODE *head=NULL;
    int a[4][4]={2,0,0,0,0,0,0,8,0,5,0,0,4,0,9,0};
    for(int i=0;i<4;i++)
      for(int j=0;j<4;j++)
      { if(a[i][j]!=0)
        head=insert_last(head,i,j,a[i][j]);
      }
    display(head);    
}