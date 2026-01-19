#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int number;
    struct Node* next;
} Node;

Node* reversal_linked_list_recursion(Node* head) {

    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* newhead = (reversal_linked_list_recursion(head->next));
    head->next->next = head;
    head->next = NULL;

}

int main(void) {

    Node* First = malloc(sizeof(Node));
    Node* Second = malloc(sizeof(Node));
    Node* Third = malloc(sizeof(Node));

    First->number = 1;
    First->next = Second;
    Second->number = 2;
    Second-> next = Third;
    Third->number = 3;
    Third->next = NULL;


}