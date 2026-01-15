#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // needed for true, false


typedef struct {
    int *data;
    int size;
    int capacity;
} Vector;

bool init_vector(Vector *v, int initial_capacity)
{
    v-> data = malloc(initial_capacity * sizeof(int));

    if (v-> data == NULL) return false;

    v-> size = 0;
    v-> capacity = initial_capacity;
    return true;
}

// Initialize: Returns false if memory allocation fails (Safety Check)


void push_back(Vector *v, int value)
{
    if (v-> size == v-> capacity) {
    v-> capacity *= 2;
    v-> data = realloc(v->data, v->capacity * sizeof(int));
    printf("Resized to %d\n", v->capacity);
    }
    *(v->data + v->size) = value;
    v->size++;
}


// get an item using Pointer Math

int get_at(Vector *v, int index)
{
    if (index >= v->size) return -1;
    return *(v-> data + index);
}


int main()
{
    return 0;
}