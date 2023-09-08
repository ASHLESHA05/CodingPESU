//insertion into an array
#include<stdio.h>
int main()
{
    int a[10]={1,2,3,4,5};
    int ele,pos;
    for(int i=0;i<5;i++)
      printf("%d ",a[i]);
    printf("enter the element and poition ");
    scanf("%d%d",&ele,&pos);
    for(int i=4;i>=pos;i--)
       a[i+1]=a[i];
    a[pos]=ele;
    for(int i=0;i<6;i++)
      printf("%d ",a[i]);

}
