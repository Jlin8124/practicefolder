#include <stdio.h>

typedef struct {
    int size;
    int capacity;
    int* data;
} Vector;

Vector* vector_new(int capacity) {
    // 1. Allocate the "Manager" (The Struct)
    // BLANK A: What goes here?
    Vector* vector = (Vector*)malloc(sizeof(Vector)); 

    // 2. Setup initial capacity logic (Power of 2)
    int true_cap = 16;
    while (true_cap < capacity) true_cap *= 2;

    // 3. Allocate the "Warehouse" (The Array)
    // BLANK B: How do we allocate the array of integers?
    vector->data = (int*)malloc(sizeof(int)* true_cap); 

    vector->size = 0;
    vector->capacity = true_cap;
    return vector;
}

void vector_push(Vector* vector, int value) {
    // 4. Check if full
    // BLANK C: What is the condition?
    if (vector->size == vector-> capacity) { 
        
        // 5. Resize logic
        // BLANK D: If we resize, what is the new size?
        int new_cap = vector->capacity * 2; 
        
        // 6. The Realloc
        // BLANK E: How do we update the data pointer?
        vector->data = (int*)realloc(vector->data, sizeof(int) * new_cap);
        vector->capacity = new_cap;
    }

    // 7. Insert the item
    // BLANK F: Where do we put the value?
    *(vector->data + vector->size) = value; 
    
    // 8. Update count
    vector->size++;
}



void insert(Vector* v, int index, int new_item) {

    if (v->size == v->capacity) {

        int new_capacity = v-> capacity * 2;

        int* new_data = (int*)realloac(v-> data, sizeof(int) * new_capacity);

        if (new_data == NULL) exit(1);

        v->data = new_data;
        v->capacity = new_capacity;
    }

    // whatever index is we need to insert the new_item
    // but first we should move everything down one

    for (int i = v->size; i > index; i--) {

        *(v->data + i) = (v-> data + i - 1);
        



    }

    *(v->data+index) = new_item;
    v->size++;
}