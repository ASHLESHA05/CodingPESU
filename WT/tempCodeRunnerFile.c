#include<stdio.h>
#include<stdlib.h>
int total(int piles[],int n)
{

}
int main()
{   
    int n,tot1=0;
    //scanf("%d",&n);
    //int *piles=calloc(n,sizeof(n));
    int piles[5]={30,11,23,4,30};
    int temp=piles[0];
    /*for(int i=0;i<n;i++)
    {
        scanf("%d",&piles[i]);
        if(piles[i]>temp)
           temp=piles[i];
        tot1+=piles[i];   
    }
    */
   tot1=98;
   temp=30;
    int h=6,k,hrs=0,tot=0;
    //scanf("%d",&h);
    for(int i=1;i<temp;i++)
    {
        tot=0;
        k=i;
        for(int j=0;j<n;){
           
           if(k>=piles[j]){
              j++;
              hrs++;
              tot+=piles[j];
           }
            else
           {
            piles[j+1]+=(piles[j]-i);
            j++;
            hrs++;
            tot+=i;
           }

       
    }
    if(hrs==h && tot==tot1)
    {
            printf("k is : %d",k);
    }
}
}