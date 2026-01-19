#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int number;
    struct Node* next;
} Node;

// function to initialize a queue of size (user input)
Node* create_queue(int number_of_boxes) {
    
    // set two pointers head and tail to NULL
    Node* head = NULL;
    Node* tail = NULL;

    // allocate memory for size of user input
    for (int i = 0; i < number_of_boxes; i++) {
        Node* new_node = malloc(sizeof(Node));
        

        Node *temp;
        // if memory allocation goes wrong clear up everything
        if (new_node == NULL) {
            while (head != NULL) {
                temp = head;
                head = head->next;
                free(temp);
            }
        return NULL;
        }
        
        // if queue is empty set both pointers to the first new node
        if (head == NULL) {
            head = new_node;
            tail = new_node;
            head->number = i;
        }
        // set the pointer of current node to the new node
        // set tail = to the new node
        else {
            tail->next = new_node;
            tail = new_node;    
            tail->number = i;
        }
    printf("Value of position: %i \n", i);
    }
    tail->next = head;
    printf("Test for last tail value next address to head: %p \n", tail->next);
        // Questions or concerns well I guess since we populated all the boxes with values
    return head;
}

void en_queue(Node* queue, int new_value) {

    // we must add a position at the tail
    // so when we first initialize the queue we give it default or random values
    // so how do we know what values are actually real 
    // 1) we could also put the number of boxes inside the function 
    // 2) because we might have queues of differnt sizes in the future


    while (queue->next != queue || queue->next != NULL) {

    }
}

int dequeue(Node** list) {

    Node* temp = *list;
    int recently_added = temp->number;
    *list = temp->next;

    free(temp);
    
    return recently_added;
}




int main(void) {

    Node* first;

    first = create_queue(7);
    Node* temp = NULL;
    Node *tempfirst = first;

    while (first != temp) {
        temp = first;
        printf("Address: %p\n", temp);
        first = first->next; 
        
        if (first == tempfirst) {
            break;
        }
    }
    
    int result = 0;
    result = dequeue(&first);
    printf("%i \n", result);

    printf("The new head address: %p \n", first);

    Node* clear = NULL;
    while (first != NULL) {
        clear = first;
        first = first->next;
        free (clear);

        if (first == tempfirst) {
            break;
        }
    }
    return 0;
}