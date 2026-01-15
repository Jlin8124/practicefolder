#include <stdio.h>
#include <stdlib.h>

#define MIN_CAPACITY 16

typedef struct IntVector {
    int* data;
    size_t size;
    size_t capacity;
    struct IntVector* next;

} IntVector;

IntVector* create_vector(size_t initial_request) {
    size_t actual_capacity = (initial_request > MIN_CAPACITY) ? next_power_of_2(initial_request) : MIN_CAPACITY;

    IntVector* vec = malloc(sizeof(IntVector));
    if (!vec) return NULL;

    vec->data = malloc(sizeof(int) * actual_capacity);
    if (!vec->data) {
        free(vec);
        return NULL;
    }
}

size_t vector_size(IntVector* vec) {
    return vec->size;
}

int main(void) {

    int* x = malloc(sizeof(int)* 5);

    *x = 42; 

    printf("%d\n", *x);

    free(x);

    IntVector* array = create_vector(16);

    size_t y = vector_size(array);

    printf("%zu", y);

    

    return 0;
}