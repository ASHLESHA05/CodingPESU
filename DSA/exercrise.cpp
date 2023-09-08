//orderly linked list
#include<iostream>
using namespace std;
typedef struct node
{
  int data;
  struct node *next;
}NODE;
void swap(int *a,int *b)
{
  int temp=*a;
  *a=*b;
  *b=temp;
}
NODE *create(int ele)
{
  NODE *newnode=(NODE*)malloc(sizeof(NODE));
  newnode->data=ele;
  newnode->next=NULL;
  return newnode;
}
NODE *insert(NODE *head,int ele)
{
  NODE *newnode=create(ele);
  newnode->next=head;
  head=newnode;
  return head;
}
void display(NODE *head)
{
  if(head==NULL)
     cout<<"empty list";
  else{
    NODE *p=head;
    while(p!=NULL)
       {
        cout<<p->data<<endl;
        p=p->next;
       }
  }     
     
}
NODE *asc_sort(NODE *head)
{
  NODE *p=head;
  for()
}
int main()
{ 
  NODE *head=NULL;
  NODE *newnode=(NODE*)malloc(sizeof(NODE));
  head=newnode;
  newnode->data=10;
  newnode->next=NULL;
  NODE *newnode1=(NODE*)malloc(sizeof(NODE));
  newnode1->data=20;
  head->next=newnode1;
  cout<<head->data;

}