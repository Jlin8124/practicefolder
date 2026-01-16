#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int number;
    struct Node* next;
} Node;

int main(void) {

    Node* head = malloc(sizeof(Node));

    head->number = 5;
    head->next = NULL;

    Node** ptr = &head;

    printf("PRINTING \n");

    printf("The address of head %p\n", (void*)ptr);
    printf("The value of head which is the address of the Node:  %p\n", (void*)*ptr);
    printf("The value of the Node:  %d\n", (**ptr).number);
    printf("The value of the Node:  %d\n", (*ptr)->number);


    return 0;
}