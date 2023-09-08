#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node* next;
    struct Node* prev;
} Node;


Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
   
    newNode->data = data;
   
    newNode->next = NULL;
   
    newNode->prev = NULL;
    return newNode;
}

void insert(Node** head, char data) {
  
    Node* newNode = createNode(data);
  
    if (*head == NULL) {
  
        *head = newNode;
    } else {
      
      
      
        Node* current = *head;
      
        while (current->next != NULL) {
            current = current->next;
      
        }
      
        current->next = newNode;
      
        newNode->prev = current;
    }
}


int isPalindrome(Node* head,int n) {
    Node *front=head;
    Node *rear=head;
    int j=0;
    while(rear->next !=NULL){
       rear=rear->next;
       j++;
    }
       int i=0;
    while(i < j){
      if(front->data != rear->data)
         return 0;
       front=front->next;
       rear=rear->prev; 
       i++; 
       j--;
    }
    return 1;
}

int main() {

    Node* head = NULL;
    int n;
    
    scanf("%d",&n);
    getchar();
    char ch[n];
    gets(ch);
   for(int i=0;i<(2*n)-1;i++){
    if(ch[i] !=' ')
    insert(&head,ch[i]);
   }


   
    
    printf("%d\n",(isPalindrome(head,n)));
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    return 0;
}
