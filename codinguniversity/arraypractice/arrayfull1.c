#include <stdio.h>
#include <stdlib.h>

const int growthFactor = 2;
const int minimumCapacity = 16;
const int shrinkFactor = 4;

typedef struct {
    int* data;
    int size;
    int capacity;
} Vector;

Vector* create_vector(int capacity) {

    Vector* vector = (Vector*)(malloc(sizeof(Vector)));

    int true_capacity = minimumCapacity;

    while (true_capacity < capacity) {
        true_capacity *= 2;
    }

    vector->size = 0;
    vector->capacity = true_capacity;

    free(vector);

    vector->data =  (int*)malloc(sizeof(int) * true_capacity);

    return vector;
}

void push(Vector* v, int new_value) {

    if (v->size == v->capacity) {
        v->capacity *= 2;
    }

    *(v->data + v->size) = new_value;
}

int main(void) {

    Vector* v = create_vector(16);

    

    push(v, 10);

    printf("%d \n", *(v->data));

    
    

    return 0;
}






















// are we returning any values first of all in the create_vector function
// yes we are returning a Vector
// cannot have a vector as a parameter yet b/c it doesn't exist, we are literally creating it
// with this function
// so what parameter do we need, the size of the vector




Vector* create_vector2(int capacity) {

    // do we allocate memory first?

    Vector* new_vector = (Vector*)malloc(sizeof(Vector));

    // we create a new pointer towards new_data or the address

    // we have to check if we need more capacity

    int new_capacity = minimumCapacity;

    // So we set a new variable to the constant why?
    // Because we want to update this variable later

    while (new_capacity < capacity) {
        new_capacity *= 2;
    }

    // why can't we just do minimumCapacity < capacity)?
    // because we'll create an infinite loop where the constant never changes
    // thats why we have to create a new variable that can increase in value and end the loop

    new_vector->capacity = new_capacity;
    new_vector->size = 0;
    new_vector->data = (int*)malloc(sizeof(int) *new_capacity);

    return new_vector;
}

// now we want to push data to this new vector
// What value are we returning if anything - nothing?

void push2(Vector*v , int new_value) {

    // do we need to check if there is space first?
    if (v->size == v->capacity) {
        // do we call resize here?
    }


}
