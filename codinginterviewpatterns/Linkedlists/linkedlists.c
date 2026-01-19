#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int number;
    struct Node* next;
} Node;

int main(void) {

    Node* First = malloc(sizeof(Node));
    Node* Second = malloc(sizeof(Node));
    Node* Third = malloc(sizeof(Node));

    First->number = 1;
    First->next = Second;
    Second->number = 2;
    Second-> next = Third;
    Third->number = 3;
    Third->next = NULL;

    printf("Address of First: %p \n", First);
    printf("Address of Second: %p \n", Second);
    printf("Address of Third: %p \n", Third);

    // how do we store these addresses in C?

    Node* current_node = malloc(sizeof(Node));
    printf("Address of current: %p \n", current_node);
    Node* prev_node = malloc(sizeof(Node));
    current_node = First;
    printf("Address of current: %p \n", current_node);
    Node* next_node = malloc(sizeof(Node));
    
    while(next_node != NULL) {
        
        next_node = current_node->next;
        current_node->next=prev_node;
        prev_node=current_node;

        if (next_node != NULL) {
        current_node=next_node;
        }

    } 

    printf("Address of First: %p \n", current_node);
    printf("Address of Second: %p \n", current_node->next);
    printf("Address of Third: %p \n", current_node->next->next);
    // printf("Address of Third: %p \n", current_node->next->next);

   free(current_node);
    



    return 0;
}