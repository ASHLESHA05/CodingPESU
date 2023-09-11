#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 100
typedef struct Stack {
    int top;
    int items[MAX];
}S;
void ini(S *stack) {
    stack->top = -1;
}

int isempty(S *stack) {
    return stack->top == -1;
}

void push(S *stack, int ele) {
    if (stack->top == MAX - 1) {
        fprintf(stderr, "Error: Stack overflow\n");
        exit(1);
    }
    stack->items[++stack->top] = ele;
}

int pop(S *stack) {
    if (stack->top == -1) {
        fprintf(stderr, "Error: Stack underflow\n");
        exit(1);
    }

    int res=stack->items[stack->top--];
    return res;
}

int evaluate(S *stack, char exp[]) {

    for (int i = strlen(exp)-1; i>= 0; i--) {
        if (isdigit(exp[i])) {
            push(stack, exp[i] - '0'); 
        } 
        else if(exp[i]!=' ')
        {

        int ele2 = pop(stack);
        int ele1 = pop(stack);
        switch (exp[i]) {
            case '+':
                push(stack,ele1+ele2);
                break;
            case '-':
                push(stack,ele1-ele2);
                break;
            case '*':
                push(stack,ele1*ele2);
                break;
            case '/':
                if (ele2 == 0) {
                    fprintf(stderr, "Error: Division by zero\n");
                    exit(1);
                }
                push(stack, ele1 / ele2);
                break;
            default:
                fprintf(stderr, "Error: Invalid operator %c\n", exp[i]);
                exit(1);
        }
        }
    }
    if (stack->top != 0) {
        fprintf(stderr, "Error: Invalid expression\n");
        exit(1);
    }
    return stack->items[stack->top];
}
int main() {
    S stack;
    ini(&stack);
    char exp[100];
    scanf("%s",exp);
    printf("%d\n",evaluate(&stack, exp));
    return 0;
}
