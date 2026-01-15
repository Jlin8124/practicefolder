#include <stdio.h>
#include <stdlib.h>

#define MIN_CAPACITY 16

typedef struct {
    int* data;
    int size;
    int capacity;
} IntVector;

void resize(IntVector* vec, size_t new_capacity) {
    if (new_capacity < MIN_CAPACITY) new_capacity = MIN_CAPACITY;

    int* new_data = realloc(vec->data, new_capacity * sizeof(int));

    if (!new_data) {
        exit(1);
    }

    vec->data = new_data;
    vec->capacity = new_capacity;
}

size_t calculate_next_power_of_2(size_t minimum_needed) {

    if (minimum_needed == 0) return 1;

    size_t capacity = minimum_needed;

    capacity--;

    capacity |= capacity >> 1; // copy original and merge with capacity shifted down 1
    capacity |= capacity >> 2;
    capacity |= capacity >> 4;
    capacity |= capacity >> 8;
    capacity |= capacity >> 16;
    

    // Now we need to check if its 64 bit 

    if (sizeof(size_t) > 4) {
        capacity |= capacity >> 32;
    }

    capacity++; // so before this ccapacity should be at the value before the next power of 2

    return capacity;

}


int main(void) {

    int* ptr = 0;

    ptr = malloc(sizeof(int) * 5);

    for (int i = 0; i < 5; i++) {

        *(ptr + i) = i;
        printf("%d\n", *(ptr+i));
    }



    return 0;

}