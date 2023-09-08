#include<iostream>
using namespace std;
typedef struct node
{
    int data;
    struct node *next;

}NODE;
void display(NODE *head)
{
    NODE *p=head;
    while(p!=NULL){
       cout<<(p->data)<<" ";
       p=p->next;
    }
}
NODE *reverse(NODE *head)
{
    NODE *p=head;
    NODE *q=NULL;
    NODE *r=NULL;
    while(p!=NULL)
    {
        r=q;
        q=p;
    }
}
int main()
{
    int n,ele;
    NODE *head=NULL,*newnode;
    cout<<"enter the number of elements\n";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>ele;
        if(i==0){
        newnode=(NODE*)malloc(sizeof(NODE));
        newnode->data=ele;
        newnode->next=head;
        head=newnode;}
        else{
            NODE *p=head;
            newnode=(NODE*)malloc(sizeof(NODE));
            while(p->next!=NULL)
               p=p->next;
            newnode->data=ele;
            p->next=newnode;
            newnode->next=NULL;   
        }

    }
    head=reverse(head);
    display(head);
}