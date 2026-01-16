#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// What are the advantages of linked lists compared to arrays
// Faster to insert and remove at the end
// The disadvantages are that it takes up more memory space

// We must create nodes - I know how to create a Node but I don't understand quite the big picture

typedef struct Node {
    int number;
    struct Node* next;
} Node;

void create_node(Node** n, int value) {
    *n = malloc(sizeof(Node));
    (*n)->number = value;
}
// functions we need to create a Node? or create a vector do we need to do that
// Vectors are for arrays that need to be dynamically resized 
// You don't need to resize Linked Lists you just keep inserting and keep updating the pointers
int size(Node* n) {
    // so you have pointers
    // we need to increment count until we reach NULL
    int count = 0;
    for (Node* temp = n; n != NULL; n = n->next)
    {
        count++;
    }
    return count;
}

bool empty(Node *n) {
    return n == NULL;
}

//  find the value at index position "user inputted"
int value_at(Node* n, int index) {
    if (n == NULL) {
        free(n);
        exit(1);
    }

    else {
       for (int i = 0; i < index; i++) {
            n = n->next;
       } 
    }

    return n->number;
}

void push_front(Node** n, int value) {
    if (n == NULL) {
        free(n);
        exit(1);
    }
    else {

        printf("Adress of ** n: %p\n", (void*)*n);
        printf("Adress of ** n: %p\n", *n);
        Node** tmp = n;
        printf("Address of temp? or n: %p \n", n);

        int temp = (*n)->number;

        printf("Address of ** tmp: %p \n", tmp);
        
        Node* new = malloc(sizeof(Node));
        new->number = value;
        new->next = *n;
         printf("Address of the next: %p \n", new->next);
    
        new->next->number = (*n)->number;
        *n = new;
        printf("Address of the new head: %p \n", new);
        printf("Address of the next: %p \n", new->next);
        printf("Address of the old head: %p \n", n);
        printf("Address of the *n: %p \n", *n);
        printf("I want to print out the previous middle node value: %i\n", new->next->next->number);

        if (new == new->next) {

            printf("Error\n");
        }
    }   
}

int main(void) {
    
    // My question is can I turn the below into a function instead of writing 3 lines of code
    // only one piece of code but I guess maybe i could set the values?
    Node* head = NULL; 
    Node* middle;
    Node* last;

    create_node(&head, 5);
    create_node(&middle, 10);
    create_node(&last, 15);

    printf("%i \n", head->number);
    
    head->next = middle;
    middle->next = last;
    last->next = NULL;

    printf("Size of linked list: %i\n", size(head));

    int empty_result = 0;

    printf("This linked list is empty: %s \n", empty(head) ? "True" : "False");
    
    printf("Value at index 2 or the 3rd element: %i \n", value_at(head, 2));
    printf("Address of head: %p \n", &head);
    printf("Address of head: %p \n", &head);
    printf("Address of first node: %p \n", head);

    push_front(&head, 50);

    printf("new value of head: %i \n", head->number);
    printf("value after new head: %i \n", head->next->number);

    Node** ptr = &head;

    printf("The pointer to pointer or the address of head: %p \n", ptr);
    printf("The address of the first node: %p \n", *ptr);
    printf("The value of the first node: %i \n", (*ptr)->number);
    
    return 0;
}