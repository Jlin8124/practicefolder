#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MINIMUM_CAPACITY 16

// Program requirements
// You have to create the vector first which is a list of related variables 
// You need to be able to add, remove, delete, insert at any point, insert at the beginning, insert at the end
// You need to be able to check the capacity, the size, if there is any elements inside
// remove value from end and return a value
// find an item and return first index with that value

typedef struct {
    
    int* data; // pointer to int data on the heap
    int size; // current number of elements in the vector
    int capacity; // maximum number of elements vector can hold
} Vector;

Vector* create_vector (int capacity) {

    Vector* new_vector = (Vector*)(malloc(sizeof(Vector)));
    // so we created a new vector called new_vector. Declared its type of it being a 
    // pointer to a Vector. malloc which allocated memory on the heap, the size of 
    // the Vector which had 3 variables so 3 x 4 bytes = 12 bytes of memory.

    // Now we need to figure out if the capacity is enough?

    int new_capacity = MINIMUM_CAPACITY;

    // if capacity is not enough than we must increase it by the power of 2 because its more efficient
    // why is it more efficient because the time and distance between increasing gets exponentially larger
    // So we have amortized O(1) to add elements

    while (new_capacity < capacity) {

        new_capacity *= 2;
    }

    new_vector->capacity = new_capacity;
    new_vector->data = (int*)(malloc(sizeof(int) * new_capacity)); 

    // don't forget to return a value

    return new_vector;
} 

void push(Vector* v, int new_value) {

    int new_capacity = 0;

    if (v->size == v->capacity) {
        int new_capacity = v->capacity * 2;
        int* new_data = realloc(v->data, sizeof(int) * new_capacity);
    
    }
}


int main(void) {

    Vector* v = create_vector(32);

    printf("%d \n", v->capacity);

    return 0;
}

