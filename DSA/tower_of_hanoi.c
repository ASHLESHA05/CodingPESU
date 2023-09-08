#include<stdio.h>
void hanoi(int n,char source,char desti,char aux){
    if(n==1){
       printf("1 from %c to %c\n",source,desti);  
       return;
    }
    hanoi(n-1,source,desti,aux);
    printf("%d from %c to %c\n",n,source,desti);
    hanoi(n-1,aux,source,desti);
}
int main(){
    int n;
    scanf("%d",&n);
    hanoi(n,'A','B','C');
    return 0;
}
