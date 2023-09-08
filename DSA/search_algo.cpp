#include<iostream>
using namespace std;
int binarysearch(int a[],int ele,int n)
{   
    int low=0,high=n-1,mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(a[mid]==ele)
          return mid;
        else if(a[mid]<ele)
         low=mid+1;
        else
         high=mid-1;   
    }
    return -1;
}
int main()
{
    int a[10]={1,2,3,4,5,6,7,8,9,10},ele,pos;
    cout<<"Enter the element u want to search";
    cin>>ele;
    pos=binarysearch(a,ele,10);
    if(pos==-1)
      cout<<"enter element not found";
    else 
      cout<<"enterd element is found in "<<pos+1<<" th position";
    return 0;  
}