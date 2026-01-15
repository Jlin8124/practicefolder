#include <stdio.h> 
#include <stdlib.h>

typedef struct Node {
    int number;
    struct Node* next;
} Node;

int main(void) {

    Node *list = NULL;

    Node *n = malloc(sizeof(Node));

    if (n == NULL) {
        free(list);
        return 1;
    }

    n->number = 1;
    n->next = NULL;
    list = n;

    n = malloc(sizeof(Node));

    if (n == NULL) {
        free(list);
        return 1;
    }

    n->number = 2;
    n->next = NULL;
    list->next = n;

    n = malloc(sizeof(Node));

    if (n == NULL) {
        free(list);
        return 1;
    }

    n->number = 3;
    n->next = NULL;
    list->next->next = n;

    printf("%d \n", list->next->next->number);

    for (Node *tmp = list; tmp != NULL; tmp = tmp->next) {
        printf("%i ", tmp->number);
    }

    while (list != NULL) {
        Node *tmp = list->next;
        free(list);
        list = tmp;

    }
    return 0;
}

// segmentation core dumped im assigning memory to a null 