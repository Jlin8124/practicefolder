#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int number;
    struct Node* next;
} Node;

void push_front(Node** n, int new_value) {
    
    Node* new_node = malloc(sizeof(Node));

    if (new_node == NULL) {
        exit(1);
    }
    new_node->number = new_value;
    new_node->next = *n;

    *n = new_node;

    // create new memory node
}

int pop_front(Node **n) {

    Node* temp = *n;

    *n = (*n)->next;
    
    free(temp);
    // I need to remove the front value, but I can't disconnect 
}


int main(void) {

    Node* new = NULL;

    push_front(&new, 5);

    Node* head = new;

    push_front(&head, 10);
    push_front(&head, 15);

    printf("Node Number: %i \n", head->number);
    printf("Node Number: %p \n", new->next);
    printf("Node Number: %d \n", head->next->next->number);
    pop_front(&head);
    printf("Value of new head post pop: %i \n", head->number);
    free(new);
    
}