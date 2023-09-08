#include<stdio.h>
#include<stdlib.h>
int kvalue(int piles[],int n,int temp1,int temp2,int tot1)
{ 
    int h=6,k,hrs=0,tot=0,piles1[n];
    printf("\nenter the hour:");
    scanf("%d",&h);
    for(int i=temp2;i<=temp1;i++)
    {   hrs=0;
        tot=0;
        k=i;
        for(int j=0;j<n;j++)
          piles1[j]=piles[j];
        int j=0;
        while(j<n){         
           if(k>=piles1[j]){
              
              hrs++;
              tot+=piles1[j];
              j++;
           }
            else
           {
            piles1[j]=piles1[j]-k;
            hrs++;
            tot+=k;
           }
           if(hrs>h)
             break;        
    }
    //printf("k=%d,hrs=%d,tot=%d\n",k,hrs,tot);
    if(hrs==h && tot==tot1)
            return k;  
}
return 0;
}
int main()
{   
    int n,tot1=0;
    scanf("%d",&n);
    int *piles=calloc(n,sizeof(n));
    int temp1=piles[0],temp2;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&piles[i]);
        if(piles[i]>temp1){
           temp1=piles[i];
           if(i==0)
             temp2=piles[i];
        }
        if(piles[i]<=temp2)
           temp2=piles[i];   
        tot1+=piles[i];

    }
     printf("\n\nk= %d",kvalue(piles,n,temp1,temp2,tot1));
}