#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct node
{   
    struct node *prev;
    int data;
    struct node *next;
}NODE;

class doublylink
{
    public:
        int choice()
        {   int choi;
            cout<<"\nEnter the choice\n";
            cout<<"\n1.insert_Begin\n2.insert_last\n3.insert_At_Specified\n4.delete_Begin\n5.delete_last\n6.delete_At_Specified\n7.show\n8.search\n";
            cin>>choi;
            return choi;
        }
        int getinfo();
        NODE *create();
        void insertionAtBeginning(NODE **);
        void insertionAtLast(NODE **);
        void insertionAtSpecified(NODE **);
        void deletionAtBeginning(NODE **);
        void deletionAtLast(NODE **);
        void deletionAtSpecified(NODE **);
        void show(NODE **);
        int search(NODE **);
};
int doublylink::getinfo()
{   
    int ele;
    cout<<"Enter element "<<endl;
    cin>>ele;
    return ele;
};
NODE *doublylink::create()
{
    NODE *newnode=(NODE*)malloc(sizeof(NODE));
    newnode->data=getinfo();
    newnode->prev=NULL;
    newnode->next=NULL;
    return newnode;
};
void doublylink::insertionAtBeginning(NODE **head)
{
    NODE *newnode=create();
    newnode->prev=NULL;
    newnode->next=*head;
    if(*head !=NULL)
       (*head)->prev=newnode;
    *head=newnode;   
    return;
};
void doublylink::insertionAtLast(NODE **head)
{
    NODE *newnode=create();
    NODE *last=*head;
    if(*head==NULL)
    {
        newnode->prev=NULL;
        *head=newnode;
        return;
    }
    while(last->next!=NULL)
    {
        last=last->next;
    }
    newnode->next=NULL;
    newnode->prev=last;
    last->next=newnode;
};
void doublylink::insertionAtSpecified(NODE **head)
{
    int pos;
    cout<<"Enter the position : ";
    cin>>pos;
    NODE *temp=*head;
    NODE *newnode=create();
    if(*head ==NULL){
     cout<<"EMPTY LIST"<<endl;
     return;
    }
    while(pos-- >1 && temp!=NULL){
        temp=temp->next;
    }
    newnode->next=temp->next;
    newnode->prev=temp;
    temp->next=newnode;
    temp->next->prev=newnode;

};
void doublylink::deletionAtBeginning(NODE **head)
{
    ;
   NODE *p=*head;
   if(*head == NULL){
      cout<<"empty list"<<endl;
      return;}
    if((*head)->next==NULL){
        *head=NULL;
        free(p);cout<<"\ndeleted\n";
        return;
    }
    
    *head =p->next; 
    p->next->prev=NULL;
    free(p);
    cout<<"\ndeleted\n"; 
    return;
}
void doublylink::deletionAtLast(NODE **head)          //   -- --    --  --
{
    NODE *last=*head;
    if(*head==NULL){
     cout<<"empty list"<<endl;
     return;}
    else if((*head)->next ==NULL){
        *head=NULL;
        free(last);return;
    } 
    while(last->next !=NULL)
       last=last->next;
    last->prev->next=NULL;
    free(last);
    return;    
}
void doublylink::deletionAtSpecified(NODE **head)
{
     int pos,count=0;
    cout<<"Enter the position : ";
    cin>>pos;
    NODE *temp=*head;
    if(head=NULL)
    {
        cout<<"Empty list"<<endl;
        return;
    }
    while(temp!=NULL)
      count++;
    if( pos < count){
    while(pos-- >1){
        temp=temp->next;
    }
    temp->prev=temp->next;
    free(temp);
    temp=NULL;
    }
    else 
     return;
}
void doublylink::show(NODE **head)
{
    if(head==NULL)
      {
        cout<<"EMpty list"<<endl;
        return;
      }
    NODE *temp=*head;
     while(temp!=NULL)
     {
        cout<<temp->data<<" ";
        temp=temp->next;
     } 
}
int doublylink::search(NODE **head){
    int ele=getinfo();
    int i=0;
    NODE *temp=*head;
    while(temp!=NULL)
    {
        if(temp->data == ele)
        {
            return i;
        }
        i++;
        temp=temp->next;
    }
    return -1;
}
int main()
{   
    NODE *head=NULL;
    doublylink a;
    int ele;
    do{
         ele=a.choice();
        switch(ele)
        {   
           
            case 1:
                a.insertionAtBeginning(&head);
                break;
            case 2:
                a.insertionAtLast(&head);
                break;  
            case 3:
                a.insertionAtSpecified(&head);
                break;
            case 4:
                a.deletionAtBeginning(&head);
                break;
            case 5:
                a.deletionAtLast(&head);
                break;
            case 6:
                a.deletionAtSpecified(&head);
                break;
            case 7:
                a.show(&head);
                break;
            case 8:
                cout<<"position : "<<a.search(&head);
                break;                          
        }
    }while(ele<=8);

}




