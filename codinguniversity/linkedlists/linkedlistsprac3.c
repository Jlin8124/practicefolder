#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int number;
    struct Node *next;
} Node;

int size(Node* n) {
    
    int count = 0;
    while (n != NULL) {
        count ++;
        n = n->next;
    }

    return count;
}

bool is_empty(Node* n) {
    if (n == NULL) {
        return true;
    }
}

int value_at(Node* n, int index) {

    int value = 0;
    int count = 0;
    // You could use a for loop and iterate up to amount times less the index
    // What about using a while loop iterate up until a counter is not ?

    for (int i = 0; i < index - 1; i++) {
        n = n->next;
    }
    
    value = n->number;
    return value;

    // is the Node* n a copy? I think so. If not i need to fix it
}

void push_front(Node* n, int new_value) {
    
    // serves as a function to add value at the start of the list 

    Node* tmp = malloc(sizeof(Node));
    tmp->next = n;
    tmp->number = new_value;
}

int pop_front(Node** n) {

    if (*n == NULL) {
        return 1;
    }

    Node* tmp = *n;
    int result = tmp->number;

    *n = (*n)->next;
    free(tmp);
    return result;
}

void push_back(Node** head, Node** tail, int new_value) {

    // need to find out how many items are in the linked list or can we just add at the end
    // find when n->next = NULL;
    // I mean I guess we defined the tail already

    Node* tmp = malloc(sizeof(Node));
    tmp->number = new_value;
    tmp->next = NULL;
    if (*head == NULL) {
        *head = tmp;
        *tail = tmp;
    }
    else {
    (*tail)->next = tmp;
    }
    *tail = tmp;
}

int front(Node* n) {
    return n->number;
}

int back(Node* n) {
    return n->number;
}

void insert(Node** n, int index, int new_value) {

    // do we have to check if node is null first?

    if (*n == NULL) {
        exit(1);
    }
    Node* current = *n;
    // looping until before the index and getting that address
    for (int i = 1; i < index - 1; i++) {
        if (current->next == NULL) {
            return;
        }
        current = current->next;
    }
    // creating a new node with memory
    Node** new_node = malloc(sizeof(Node));

    // assigning the inserted value at new node
    // pointing new node to the node @ index previously
    (*new_node)->number = new_value;
    (*new_node)->next = (*n)->next;
    // pointing node at index - 1 previously to new node;
    (*n)-> next = (*new_node);
    
}

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
    
    printf("%i \n", head->number);
    printf("%i \n", head->next->number);
    // how do check if their linked properly
    // do I need a general list to point to the head
    // do I need to free memory
    int countofpracticelist = size(head);
    printf("%i \n", countofpracticelist);

    Node* empty = NULL;

    bool result = is_empty(empty);
    printf("%s \n", result ? "True" : "False");

    int value_check = 0;

    value_check = value_at(head, 2);

    printf("Value Check: at index 2: %i \n", value_check);

    // okay with the pop function i can pop off 1 
    // then if i use value check at head 0 the value should be 2

    pop_front(&head);
    value_check = value_at(head, 0);
    printf("Popped off 1st position: %i \n", value_check);

    printf("Front value post pop: %i \n", front(head));

    printf("Last value check: %i \n", back(last));

    printf("Checking inserting Node Function : \n");

    insert(&head, 2, 5);

    value_check = value_at(head, 2);

    printf("Value Check: at index 2 should be 5: %i \n", value_check);
    

    while (head != NULL) {
        Node* tmp = head->next;
        free(head);
        // after you free head hext->next and head->value don't exist anymore
        // so you have use the tmp value you stored
        head = tmp;
    }
    // list -> head - > middle -> last

    return 0;
}