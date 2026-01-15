#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 16

typedef struct {
    int* data;
    int size;
    int capacity;
} DynamicArray;

void init(DynamicArray* arr) {
    arr->capacity = INITIAL_CAPACITY;
    arr->size = 0;
    arr->data = malloc(arr->capacity * sizeof(int));
}

void grow(DynamicArray* arr) {
    arr->capacity *= 2;
    arr->data = realloc(arr->data, arr->capacity * sizeof(int));

}

void push(DynamicArray* arr,  int value) {
    if (arr->size == arr-> capacity) {
        grow(arr);
    }

    arr->data[arr->size] = value;
    arr->size++;

}

int main(void) {
    
    DynamicArray array;

    init(&array);

    push(&array, 5);

    printf("%d\n", *array.data);


    return 0;
}