#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define max 100
typedef struct {
    int items[max];
    int top;
} Stack;
void ini(Stack *stack) {
    stack->top = -1;
}
bool isEmpty(Stack *stack) {
    return stack->top == -1;
}

bool isFull(Stack *stack) {
    return stack->top == max - 1;
}
void push(Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        exit(1);
    }
    stack->items[++stack->top] = value;
}
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        exit(1);
    }
    int res=stack->items[stack->top--];
    return res;
}
int evel(Stack *stack,char *exp) {
    for (int i =strlen(exp)- 1;i >= 0; i--) {
        if (isdigit(exp[i])) {
            int operand = exp[i] - '0';
            push(stack, operand);
        } else if (exp[i] == ' ') {
            continue;
        } else {
            if (isEmpty(stack)) {
                printf("Invalid exp\n");
                exit(1);
            }
            int operand1=pop(stack);
            if (isEmpty(stack)) {
                printf("Invalid exp\n");
                exit(1);
            }
            int operand2=pop(stack);

            switch (exp[i]) {
                case '+':
                    push(stack, operand1 + operand2);
                    break;
                case '-':
                    push(stack, operand1 - operand2);
                    break;
                case '*':
                    push(stack, operand1 * operand2);
                    break;
                case '/':
                    if (operand2 == 0) {
                        printf("Division by zero\n");
                        exit(1);
                    }
                    push(stack, operand1 / operand2);
                    break;
                default:
                    printf("Invalid operator\n");
                    exit(1);
            }
        }
    }

    if (isEmpty(stack) || stack->top != 0) {
        printf("Invalid exp\n");
        exit(1);
    }
    return stack->items[stack->top];
}

int main() {
    Stack *stack;
    ini(stack);
    char exp[100];
    scanf("%s",exp);
    printf("%d\n",evel(stack,exp));
    return 0;
}
