#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int number;
    struct Node *next;
} Node;


int main (void) {

    Node *list = NULL;

    // Let's try to create a Node or list with 5 values
    // Print them out
    // Free the memory afterwards

    Node* n = malloc(sizeof(Node));
    list = n;

    if (list == NULL) {
        free(list);
        exit(1);
    }
    n->number = 1;
    n->next = NULL;
    list = n;
    
    // could be a node type too? do i have to add int on the other side? 
    

    n = malloc(sizeof(Node));
    
        if (n == NULL) {
        free(list);
        exit(1);
    }
    n->number = 2;
    n->next = NULL;
    list->next = n;
    n = malloc(sizeof(Node));
    
        if (n == NULL) {
        free(list);
        exit(1);
    }

    list->number = 3;
    list->next->next = n;




    // do i have to free the list anywhere



}