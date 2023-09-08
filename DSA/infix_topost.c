#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
int top=-1;
char stack[20];
int presi(char ele1,char ele2){
    int pele1,pele2;
    if(ele1=='+' || ele1=='-')
      pele1=0;
    else if(ele1=='*' || ele1=='/')
      pele1=1;
    else 
      pele1=2; 
    if(ele2=='+' || ele2=='-')
      pele2=0;
    else if(ele2=='*' || ele2=='/')
      pele2=1;
    else 
      pele2=2;  

    if(pele2<=pele1)
       return 1;
    else
       return 0;  
}
int isempty()
{
    if(top==-1)
      return 1;
    else  
      return 0;
}

void push(char ele){

    static int i=0;
    top=i;
    i++;
    stack[top]=ele;
}
void pop()
{  
    if(!isempty())
      top--;

}
char display()
{
    return stack[top];
}


int main(){
    char st[20]="a+b";
    
    for(int i=0;i<strlen(st);i++){
        switch(st[i]){
            case '(':
               push('(');
               break;
            case ')':
               while(stack[top]!='('){
               printf("%c",stack[top]);
               pop();
               }
               pop();
               break;
            default:
                if(!isalnum(st[i])) {
                if(presi(stack[top],st[i])){  //if input has less or equal presidency
                    printf("%c",stack[top]);
                    pop();
                    push(st[i]);
               } 
                 else
                    push(st[i]); 
                }
                else
                   printf("%c",stack[top]);
                break;   

        }
    }
    puts(st);


}