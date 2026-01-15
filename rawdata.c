#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MIN_CAPACITY = 16

typedef struct{
    int* data;
    size_t size;
    size_t capacity;
} IntVector;

size_t next_power_of_2(size_t n) {
    if (n == 0) return 1; 

    n--;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;


    if (sizeof(size_t) > 4) {
        n |= n >> 32;
    }

    n++;
    return n;
}

void push_back(IntVector* vec, int value) {
    // 2. Check if full

    if (vec->size == vec-> capacity) {
        printf("Error: Vector is full!\n");
        return;
    }

    vec->data[vec->size] = value;

    vec->size++;
}

int main(void) {


    return 0;

}