
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
  int ele;
  struct node *next;
}NODE;
//******************************************
NODE *create(int ele)
{
  NODE *newnode=malloc(sizeof(NODE));
  newnode->ele=ele;
  newnode->next=NULL;
  return newnode;
}
//*******************************************
NODE *insert_front(NODE *head,int ele)
{
  NODE *newnode=create(ele);
  newnode->next=head;
  head=newnode;
  return head;
}
//*******************************************
void display(NODE *head)
{ 
  printf("\n");  
  NODE *p=head;
  while(p!=NULL)
  {
    printf("%d ",p->ele);
    p=p->next;
  }

  printf("\n");
}
//********************************************
NODE *delete_front(NODE *head)
{
  NODE *p=head;
  head=(head)->next;
  free(p);
  return head;
}
//********************************************
NODE *insert_last(NODE *head,int ele)
{
  NODE *newnode=create(ele);
  NODE *p=head;
  while(p->next!=NULL)
    p=p->next;
  p->next=newnode;
  return head;  
}
//*********************************************
NODE *delete_last(NODE *head)
{
  NODE *p=head;
  NODE *temp=head;
  if((head)->next==NULL)
  {
   p=head;
   head=NULL;
   free(p); 
   return head;
  }
  else{

  while(p->next!=NULL)
  {
    temp=p;
    p=p->next;
  }
  temp->next=NULL;
  free(p);
}}
//**********************************************
int size(NODE *head)
{
  NODE *p=head;
  int i=0;
  while(p->next!=NULL)
  {
    i++;
    p=p->next;
  }
  printf("size id :%d\n",i+1);
  return(1+i);
}
//**********************************************
NODE *insert_pos(NODE *head,int ele,int pos)
{
  int len=size(head);
  if(head==NULL)
  {
    head=create(ele);
    return head;
  }
  else{
    NODE *newnode=create(ele);
    NODE *p=head;
    while(pos-- >1)
      p=p->next;
    newnode->next=p->next;
    p->next=newnode;
    return head;  

  }
}

//********************************************************************
NODE *delete_pos(NODE *head,int ele)
{ 
  if(ele==0){
      head=delete_front(head);
      return head;
}
  else if(size(head)-1 >=ele)
  {
    NODE *p=head,*temp;
    int i=0;
    while(i!=ele)
    {
       temp=p;
       p=p->next;
       i++;
    }
    temp->next=p->next;
    free(p);
  }
  else
    printf("Invalid position entered \n");
}
//********************************************************
NODE *delete_middle(NODE *head)
{
  int n=size(head);
  NODE *p=head,*temp;
  int mid=n/2;
  if(head==NULL)
    printf("empty list\n");
   else{
    if(head->next==NULL)
       {
       free(p);
       head=NULL;
       return head;}
     else{
      while(mid-- >1)
      { temp=p;
        p=p->next;
      }
      temp->next=p->next;
      free(p);
      return head;
     }  
   }   
}
//****************************************************
NODE *insert_middle(NODE *head,int ele)
{
  if((head==NULL) || (head->next==NULL)){
    printf("insufficient number of elements!!");
    return head;}
  else{

    NODE *p=head;
    int mid;

    if(size(head)%2==0)
      mid=size(head)/2;
    else 
      mid=size(head)/2 +1; 

    while(mid-- >1)
    {
      p=p->next;
    }
    NODE *newnode=create(ele);
    newnode->next=p->next;
    p->next=newnode;
    return head;  
  }  

}
//*************************************************
NODE *freenode(NODE *head)
{
  if(head==NULL)
     printf("empty list\n");
  else{
    NODE *p=head,*temp=head;
    while(p!=NULL)
    {  
      temp=p;
      p=p->next;
      free(temp);
    }
    printf("every element deleated!!\n\n");
  }  
  return NULL; 
}
//**************************************************
int search_key(NODE *head,int ele)
{
  NODE *p=head;
  int pos;
  while(p!=NULL)
  {
     if(p->ele ==ele){
     return pos;
     }
     p=p->next;
     pos++;
  }
  return -1;
}
//******************************************************
void swap(NODE **p,NODE **q)
{
  NODE *temp=*p;
   *p=*q;
   *q=temp;
}
//*******************************************************
NODE *asc_sort(NODE *head)
{
  NODE *p=head;
  int size=sizeof(head)-1;
  for(int i=0;i<size-1;i++)
     { 
      p=head;
      for(int j=0;j<size-i-1;i++){
        if(p->ele > p->next->ele)
        {
          swap(&p,&(p->next));
          if(p==head)
           head=p->next;

        }
      }
     }
  return head;   
}


int main()
{
  NODE *head=NULL;
  int n,ele,pos;
  do{
    printf("1.insert_front front\n2.display\n3.delete_front\n4.insertlast\n5.deletelast\n6.insert pos\n7.delete frm pos\n8.delete middle\n9.insert middle\n10.free\n0exit\n");
    printf("\n\n11.search ele\n12.ascending sort\n");
    scanf("%d",&n);
    switch(n)
    { 
        case 1:
          printf("enter the elements");
          scanf("%d",&ele);
          head=insert_front(head,ele);
          break;

        case 2:
          if(head!=NULL)
          display(head);
          else
           printf("empty list\n"); 
          break;

        case 3:
          if(head!=NULL)
           head=delete_front(head);
          else 
            printf("Empty list");  
          break;

        case 4:
           printf("enter element:  ");
           scanf("%d",&ele);
           head=insert_last(head,ele);
           break;

        case 5:
          if(head!=NULL)
           head=delete_last(head);
          else 
            printf("Empty list");  
          break;  
        case 6:
           printf("enter the element and position");
           scanf("%d%d",&ele,&pos);
          if(size(head)>=pos)
           head=insert_pos(head,ele,pos);
          else 
            printf("\nInvalid position\n");
           break;
        case 7:
           if(head==NULL)
           printf("empty list\n");
           else
           {
            printf("enter the position u want to pop");
            scanf("%d",&ele);
            if(size(head)>=pos)
            head=delete_pos(head,pos);
            else
             printf("\nInvalid position\n");
            break;
           }
        case 8:
           head=delete_middle(head);
           break;
        case 9:
           printf("enter element: ");
           scanf("%d",&ele);
           head=insert_middle(head,ele); 
           break;
        case 10:
           head=freenode(head);
           break; 
        case 11:
           printf("\nenter the element to search\n");
           scanf("%d",&ele);
           if(search_key(head,ele)!=-1)
             printf("postion: %d",search_key(head,ele));
           else
             printf("NOT FOUND\n");
           break; 
        case 12:
           head=asc_sort(head);              
                            
    }
  }while(n<=13 && n>=1);
}