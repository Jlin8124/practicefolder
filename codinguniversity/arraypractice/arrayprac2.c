#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MINIMUM_CAPACITY 16

typedef struct {

    int* data;
    int size;
    int capacity;
} Vector;

Vector* create_vector(int capacity) {

    Vector* v = (Vector*)malloc(sizeof(Vector)); 

    // create size first? 

    int new_capacity = MINIMUM_CAPACITY;

    while (new_capacity < capacity) {

        new_capacity = capacity *2;
    }

    int* new_data = (int*)malloc(sizeof(int) * new_capacity);

    v->size = 0;
    v->capacity = new_capacity;
    v->data = new_data;

    return v; // need to return vector as per the function itself starting with V*
   
}

int size(Vector* v) {
    return v->size;
}

int capacity(Vector* v) {
    return v->capacity;
}

bool is_empty(Vector* v) {
    return v->size == 0;
}

int at_index(Vector* v, int index) {

    if (index < 0 || index > v->size) {
        
        exit(1);

    }

    else {
        return *(v->data + index);
    }

}

void push(Vector* v, int new_item) {
    
    int new_capacity;
    // do we have to resize first?

    if (v->size == v->capacity) {

        new_capacity = v->capacity * 2;
        v->capacity = new_capacity;
        int* new_data = (int*)realloc(v->data, sizeof(int) * new_capacity);
        v->data = new_data; // needed to assign the address of the new data to v-> data
    }

    
    
    *(v->data + v->size) = new_item;
    v->size++;

}

void insert(Vector* v, int index, int new_item) {
    
    // what about edge cases where the index given is outside of 0 and outside the max

    if (index < 0 || index >= v->size) {
         exit(1);
    }
    int new_capacity;
    // do we have to resize first?

    if (v->size == v->capacity) {

        new_capacity = v->capacity * 2;
        v->capacity = new_capacity;
        int* new_data = (int*)realloc(v->data, sizeof(int) * new_capacity);
        if (new_data == NULL) exit(1);
    }

    

    // copy it from the left because if you iterate forward youre just going to be looping
    // the same value over and over again
    v->size++;

    for (int i = v->size; i > index; i--) {
        *(v->data + i) = *(v->data + (i - 1));

    }

    *(v->data + index) = new_item;
    

}

void prepend(Vector* v, int new_value) {
    insert(v, 0, new_value);

}

int pop(Vector* v) {

    int end_value = *(v->data + (v->size -1));

    v->size--;

    return end_value;


}

void delete(Vector* v, int index) {

    // need to iterate forward if all elements moving left. 
    for (int i = index; i < v->size; i++) {

        *(v->data + i) = *(v->data + i); 
        }

    v->size--;

}

void remove2(Vector* v, int removed_value) {

    for (int i = 0; i<v->size; i++) {
        // is there a faster way to go through everything faster

        if (*(v->data+i) == removed_value) {
            delete(v, i);
        }

    }

}

void remove_vector_fast(Vector* v, int removed_value) {

    int writer = 0; // The "Keep Pointer"

    for (int reader = 0; reader < v->size; reader++) {

        if (*(v->data + reader) != removed_value) {
            *(v->data+writer) = *(v->data + reader);
            writer++; 
        } 
    
    }
    v->size = writer;
}

int find(Vector* v, int value) {

    for (int i = 0; i < v->size; i++) {
        if (*(v->data+i) == value)
        return i;
    }

    return -1;    
}


int main(void) {
    
    Vector* newvector = create_vector(16);

    push(newvector, 5);
    push(newvector, 6);
    push(newvector, 7);
    push(newvector, 8);

    for (int i = 0; i<4; i++) {
        printf("%d \n", *(newvector->data + i));
    }

    printf("Value at 0: %d \n", *(newvector->data));

    int size2 = capacity(newvector);

    printf("%d\n", size2);

    int size3 = at_index(newvector, 2);

    printf("%d \n", size3);

    printf("Inserting number 113 at index 2 \n");

    insert(newvector, 2, 113);

    size3 = at_index(newvector, 2);

    printf("%d \n", size3);

    printf("%d \n", *(newvector->data));

    printf("%d \n", (newvector->size));

    printf("This is the current end value: %d\n", *(newvector->data + (newvector->size - 2)));

    printf("Testing delete function\n");

    for (int i = 0; i < newvector->size; i++) {
        printf("%d, ", *(newvector->data + i));
    }
    printf("\n");

    printf("Testing the find item function \n");

    return 0;
}