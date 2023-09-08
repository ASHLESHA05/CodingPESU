//prefix_postfix
#include<stdio.h>
#include<string.h>
#include <errno.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
#define MAX 100
typedef struct Stack{
    int top;
    int items[MAX];
}S;
void ini(S *stack){
    stack->top=-1;
}
int isempty(S *stack){
    return stack->top==-1;
}
void push(S *stack,int ele){
    if(stack->top ==MAX-1){
        fprintf(stderr,"Error: Stack overflow\n");
        exit(0);
    }
    stack->top+=1;
    
    stack->items[stack->top]=ele;
    printf("pushed element %d\n",stack->items[stack->top]);
    stack->top+=1;
}
void pop(S *stack)
{
       if(stack->top ==-1){
        fprintf(stderr,"Error: Stack underflow\n");
        exit(0);
    }
    stack->top--;


}
int evel(S *stack,char exp[]){
    int res;
    for(int i=strlen(exp)-1;i>=0;i--){
       
        if(exp[i]!='/' && exp[i]!='*' && exp[i]!='+' && exp[i]!='-')
          {
          printf("pushed : : ");
          push(stack,atoi(&exp[i]));}
        else{
        
            if(exp[i]=='/'){
                res=stack->items[stack->top]/stack->items[stack->top-1];
                pop(stack);
                pop(stack);
                push(stack,res);
                //stack->top--;   
            }
            else  if(exp[i]=='*'){
                res=stack->items[stack->top]*stack->items[stack->top-1];
                pop(stack);
                pop(stack);
                push(stack,res);
               // stack->top--;   
            }
            else  if(exp[i]=='+'){
                res=(stack->items[stack->top])+(stack->items[stack->top-1]);
                printf("%d\n",res);
                pop(stack);
                pop(stack);
                push(stack,res);
                //stack->top--;   
            }
            else  if(exp[i]=='-'){
                res=stack->items[stack->top]-stack->items[stack->top-1];
                pop(stack);
                pop(stack);
                push(stack,res);
               // stack->top--;   
            }

               
        }  
    }
    return stack->items[0];
}
int main(){
    S *stack;
    char exp[3]="+53";
    //fgets(exp,100,stdin);
    exp[strcspn(exp,"\n")]='\0';
    int result=evel(stack,exp);
    printf("%d\n",result);
    return 0;
}
