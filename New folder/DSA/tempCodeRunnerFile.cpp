#include<iostream>
using namespace std;
typedef struct node
{
  int data;
  struct node *next;
}NODE;
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