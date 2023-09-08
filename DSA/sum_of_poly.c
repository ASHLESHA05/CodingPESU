#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    int exp;
    struct node *next;
}NODE;
NODE *createnode(int coeff,int exp)
{
    NODE *newnode=(NODE*)malloc(sizeof(NODE));
    newnode->data=coeff;
    newnode->exp=exp;
    newnode->next=NULL;
    return newnode; 
}
NODE *insert_front(NODE *head,int coeff,int exp)
{
  NODE *newnode=createnode(coeff,exp);
  newnode->next=head;
  head=newnode;
  return head;
}
NODE *insert_last(NODE *head,int coeff,int exp)
{
  if(head==NULL){
      head=insert_front(head,coeff,exp);
      return head;}
  NODE *newnode=createnode(coeff,exp);
  NODE *p=head;
  while((p->next)!=NULL)
    p=p->next;
  p->next=newnode;
  return head;  
}

void display(NODE *head)
{ 
  NODE *p=head;
  while(p!=NULL)
  {
    printf("%d ",p->data);
    p=p->next;
  }
}
NODE *sum(NODE *head1,NODE *head2,NODE *head3)
{
   
    NODE *p3=head3;
    while(head1!=NULL || head2!=NULL)
    {
        if(head1==NULL)
        {
            head3->data=head2->data;
            head2=head2->next;
            break;
          }
        if(head2==NULL)
        { head3->data=head1->data;
              head1=head1->next;
              break;}
        if(head1->exp==head2->exp)
        {   
            head3->data=(head1->data+head2->data);
            head1=head1->next;
            head2=head2->next;}
       else if(head1->exp > head2->exp)
            { head3->data=head1->data;
              head1=head1->next;}
        else
        {
            head3->data=head2->data;
            head2=head2->next;}
        head3=head3->next;      
    }
    return p3;   
}
int main() {
    NODE *head1=NULL;
    NODE *head2=NULL;
    NODE *head3=NULL;
    int n,m,p,q;
   scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d%d",&p,&q);
    head1=insert_last(head1,p,q);
    }
    for(int i=0;i<m;i++){
        scanf("%d%d",&p,&q);
    head2=insert_last(head2,p,q);
    }
      for(int i=0;i<m+n-1;i++)
        head3=insert_last(head3,0,0);
    head3=sum(head1,head2,head3);
    display(head3);
    return 0;
}
