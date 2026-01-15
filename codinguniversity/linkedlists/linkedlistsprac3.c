#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int number;
    struct Node *next;
} Node;


int main(void) {

    Node* head = malloc(sizeof(Node));
    Node* middle = malloc(sizeof(Node));
    Node* last = malloc(sizeof(Node));

    head->number = 1;
    head->next = middle;
    middle->number = 2;
    middle->next = last;
    last->number = 3;
    last->next = NULL;

    


}