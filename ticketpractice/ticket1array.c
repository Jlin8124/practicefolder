#include <stdio.h>
#include <stdlib.h>

#define MIN_CAPACITY 16

// --- THE STRUCT ---
typedef struct {
    int* data;      // The "Hidden" Array
    size_t size;    // Items currently stored
    size_t capacity;// Total slots available
} IntVector;

// --- PRIVATE HELPERS ---

size_t next_power_of_2(size_t n) {
    if (n == 0) return 1;
    n--;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    // if (sizeof(size_t) > 4) n |= n >> 32; // Uncomment for 64-bit specific optimization
    n++;
    return n;
}

void resize(IntVector* vec, size_t new_capacity) {
    if (new_capacity < MIN_CAPACITY) new_capacity = MIN_CAPACITY;
    
    int* new_data = realloc(vec->data, new_capacity * sizeof(int));
    if (!new_data) {
        printf("Error: Memory allocation failed during resize.\n");
        exit(1);
    }
    
    vec->data = new_data;
    vec->capacity = new_capacity;
}

// --- CORE FUNCTIONS ---

IntVector* create_vector(size_t initial_request) {
    IntVector* vec = malloc(sizeof(IntVector));
    if (!vec) return NULL;

    size_t actual_capacity = (initial_request > MIN_CAPACITY) 
                             ? next_power_of_2(initial_request) 
                             : MIN_CAPACITY;

    vec->data = malloc(actual_capacity * sizeof(int));
    if (!vec->data) { free(vec); return NULL; }

    vec->size = 0;
    vec->capacity = actual_capacity;
    return vec;
}

void push(IntVector* vec, int item) {
    if (vec->size == vec->capacity) {
        resize(vec, vec->capacity * 2);
    }
    *(vec->data + vec->size) = item;
    vec->size++;
}

void delete_at(IntVector* vec, size_t index) {
    if (index >= vec->size) return;

    // Shift left to fill hole
    for (size_t i = index; i < vec->size - 1; i++) {
        *(vec->data + i) = *(vec->data + (i + 1));
    }

    vec->size--;

    if (vec->size > 0 && vec->size == vec->capacity / 4) {
        resize(vec, vec->capacity / 2);
    }
}

// --- YOUR TASK STARTS HERE ---

// TODO: Implement pop_front()
// Requirements:
// 1. Return the value at index 0.
// 2. Shift everything left.
// 3. Resize down if needed (reuse logic if possible).
int pop_front(IntVector* vec) {
    // Write your code here...
    return -1; // Placeholder
}

// --- TEST MAIN ---
int main() {
    IntVector* v = create_vector(16);
    
    // Setup: Push 10, 20, 30
    push(v, 10);
    push(v, 20);
    push(v, 30);

    printf("Vector before pop_front: 10, 20, 30\n");

    // TEST YOUR CODE HERE
    // int val = pop_front(v);
    // printf("Popped: %d\n", val); // Should be 10
    // printf("New First Item: %d\n", *(v->data)); // Should be 20

    return 0;
}