#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int number;
    struct Node* next;
} Node;

Node* create_node(int number_of_boxes) {

    Node* head = NULL;
    Node* tail = NULL;

    for (int i = 0; i < number_of_boxes; i++) {
        Node* new_node = malloc(sizeof(Node));
        // we set it to NULL right now because we don't want it pointing to some garbage memory data

        

        if (new_node == NULL) {
            Node* temp; // create a box or a node called temp ONCE
            while( head != temp) {
                temp = head; // Putt an address in the box.
                head = head->next; // change head.
                free(temp); // Empty the memory temps points to
            }

        return NULL;
        }
        if (head == NULL) {
            head = new_node;
            tail = new_node;
        }

        else {
            tail->next = new_node;

        }
        
    }
}

void enqueue(Node* list, int new_value) {

    // if tail is at the end, then we have to rewrite the start

    // so first we must find out if the list is at the tail
    Node* temp;

    if (list == NULL) {
        list->number = new_value;
    }

    while ( list!= NULL) {
        temp = list;
        list = list->next;

        if (list->next = temp) {
            temp->number = new_value;
        }

        else {
            list = new_value;
        }
    }
}

int main (void) {

    Node* first = create_node(7);
    
    for (int i = 0; i < 7; i++) {
        printf("Memory address: %p \n", (first+i));
    }



    // Do i have to create a node or vector for this
    // Do i use a linked list or an array
    // I need a pointer
}