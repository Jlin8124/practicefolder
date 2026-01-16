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

        // store OLD head in new memory address? or temporary one
        // So we are creating a temporary double ** tmp node and storing n in it
        // What is n is the actual version of the pointer to pointer from main not just a copy
        // so we store the actual keys to the head variable in n

        Node** tmp = n;
        printf("Address of temp? or n: %p \n", n);

        int temp = (*n)->number;
        
        // we free n because? we don't want the head address pointing towards the old value anymore
        // but then we still need the old head to point towards the middle
        // i have to store the next address too
        
        
        // idk why we freed *n which is just the pointer to the first node, 
        // i guess because we don't want it pointing to the first node anymore
        // what would freeing just n do it would free the entire double pointer structure which we dont want
        // can you free ** n? no because thats the actual value of the first node? or the address of the first node maybe then
        printf("Address of ** tmp: %p \n", tmp);
        
        // create a new memory address for the new value
        // assign the new memory address the new value
        // assign the next in the linked list to n? but we freed up n so how does that work
        Node* new = malloc(sizeof(Node));
        new->number = value;
        //new->next = (void*)tmp;
        new->next = *tmp;
        *n = new;

        new->next->number = temp;

        printf("Address of the new head: %p \n", new);
        printf("Address of the next: %p \n", new->next);
        printf("Address of the old head: %p \n", n);
        // we need to set the new value to point towards the old head
        // and the pointer to pointer to point to the new node

        
        printf("I want to print out the previous middle node value: %i\n", new->next->next->number);
    }
}

int main(void) {
    
    // My question is can I turn the below into a function instead of writing 3 lines of code
    // only one piece of code but I guess maybe i could set the values?
    Node* head; 
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
    
    return 0;
}