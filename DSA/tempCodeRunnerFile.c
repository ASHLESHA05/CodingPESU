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


int isPalindrome(Node* head) {
    if (head == NULL) {
        return 1; 
    }

    Node* front = head;
    Node* back = head;

    
    
    while (back->next != NULL) {
        back = back->next;
    }

    while (front != back && front->prev != back) {
      
        if (front->data != back->data) {
            return 0; 
        }
    
    
        front = front->next;
    
    
        back = back->prev;
    }

    return 1; 
}

int main() {

    Node* head = NULL;
    int n;
    char ch;
    scanf("%d",&n);
   for(int i=0;i<n;i++){
    scanf("%c",&ch);
    insert(&head,ch);
   }

   
    
    printf("%d\n",(isPalindrome(head)));
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    return 0;
}
