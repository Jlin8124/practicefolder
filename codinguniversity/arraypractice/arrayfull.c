#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const int kMinCapacity = 16;
const int kGrowthFactor = 2;
const int kShrinkFactor = 4;

typedef struct {
    int size;      // Number of items currently used
    int capacity;  // Total storage space available
    int* data;     // Pointer to the raw memory block
} Vector;

// --- Private Helper ---
// Resizes the underlying array to a specific capacity
void vector_resize(Vector* vector, int new_capacity) {
    // If the new capacity is less than our minimum (16), don't shrink too far
    if (new_capacity < kMinCapacity) {
        // However, if we are effectively empty, we might just stay at min.
        if (vector->capacity > kMinCapacity) {
             new_capacity = kMinCapacity;
        } else {
            return; // Already at minimum
        }
    }

    int* new_data = (int*)realloc(vector->data, sizeof(int) * new_capacity);
    
    // Safety check: if realloc fails
    if (new_data == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }

    vector->data = new_data;
    vector->capacity = new_capacity;
}

// --- Public API ---

// 1. Initialize Vector
// Starts with 16 slots.
Vector* vector_new(int capacity) {
    Vector* vector = (Vector*)malloc(sizeof(Vector));
    
    // Determine initial capacity (start with 16 or user defined)
    int true_capacity = kMinCapacity;
    while (true_capacity < capacity) {
        true_capacity *= 2; // Keep doubling until we fit the request (Power of 2)
    }

    vector->size = 0;
    vector->capacity = true_capacity;
    vector->data = (int*)malloc(sizeof(int) * true_capacity);

    return vector;
}

// 2. Size & Capacity
int vector_size(Vector* vector) {
    return vector->size;
}

int vector_capacity(Vector* vector) {
    return vector->capacity;
}

bool vector_is_empty(Vector* vector) {
    return vector->size == 0;
}

// 3. Access at Index
// Uses pointer math: *(start_address + index)
int vector_at(Vector* vector, int index) {
    if (index < 0 || index >= vector->size) {
        printf("Error: Index out of bounds.\n");
        exit(1);
    }
    return *(vector->data + index); 
}

// 4. Push (Add to end)
void vector_push(Vector* vector, int value) {
    if (vector->size == vector->capacity) {
        vector_resize(vector, vector->capacity * kGrowthFactor);
    }
    
    // Write value using pointer arithmetic
    *(vector->data + vector->size) = value;
    vector->size++;
}

// 5. Insert at Index
void vector_insert(Vector* vector, int index, int value) {
    if (index < 0 || index > vector->size) {
        printf("Error: Index out of bounds.\n");
        exit(1);
    }

    if (vector->size == vector->capacity) {
        vector_resize(vector, vector->capacity * kGrowthFactor);
    }

    // Shift elements to the right to make space
    // We start from the end and move backwards
    for (int i = vector->size; i > index; i--) {
        *(vector->data + i) = *(vector->data + i - 1);
    }

    *(vector->data + index) = value;
    vector->size++;
}

// 6. Prepend (Add to front)
void vector_prepend(Vector* vector, int value) {
    vector_insert(vector, 0, value);
}

// 7. Pop (Remove from end)
int vector_pop(Vector* vector) {
    if (vector->size == 0) {
        printf("Error: Pop from empty vector.\n");
        exit(1);
    }

    int value = *(vector->data + (vector->size - 1));
    vector->size--;

    // Shrink logic: if size is 1/4 of capacity, resize to half
    if (vector->size > 0 && vector->size == vector->capacity / kShrinkFactor) {
        vector_resize(vector, vector->capacity / 2);
    }

    return value;
}

// 8. Delete at Index
void vector_delete(Vector* vector, int index) {
    if (index < 0 || index >= vector->size) {
        printf("Error: Index out of bounds.\n");
        exit(1);
    }

    // Shift elements to the left to fill the gap
    for (int i = index; i < vector->size - 1; i++) {
        *(vector->data + i) = *(vector->data + i + 1);
    }

    vector->size--;

    // Same shrink logic as pop
    if (vector->size > 0 && vector->size == vector->capacity / kShrinkFactor) {
        vector_resize(vector, vector->capacity / 2);
    }
}

// 9. Find (Returns index of first occurrence, or -1)
int vector_find(Vector* vector, int value) {
    for (int i = 0; i < vector->size; i++) {
        if (*(vector->data + i) == value) {
            return i;
        }
    }
    return -1;
}

// 10. Remove (Delete by value)
// Removes ALL instances of the value (based on "even if in multiple places")
void vector_remove(Vector* vector, int value) {
    for (int i = 0; i < vector->size; i++) {
        if (*(vector->data + i) == value) {
            vector_delete(vector, i);
            i--; // Decrement i because everything shifted left
        }
    }
}

// Destructor (Clean up memory)
void vector_free(Vector* vector) {
    free(vector->data);
    free(vector);
}

// --- Testing usage ---
int main() {
    // 1. New raw data array
    Vector* v = vector_new(5); // Will round up to 16
    printf("Initial Capacity: %d\n", vector_capacity(v));

    // 2. Push items
    for (int i = 0; i < 20; i++) {
        vector_push(v, i);
    }
    printf("Size after pushing 20 items: %d\n", vector_size(v));
    printf("Capacity (doubled): %d\n", vector_capacity(v));

    // 3. Insert and Prepend
    vector_insert(v, 5, 999);
    vector_prepend(v, 111);
    
    // 4. Access
    printf("Item at index 0: %d\n", vector_at(v, 0));       // Should be 111
    printf("Item at index 6: %d\n", vector_at(v, 6));       // Should be 999
    
    // 5. Pop and Shrink
    printf("Popped: %d\n", vector_pop(v)); // Remove last
    
    // 6. Delete and Remove
    vector_delete(v, 0); // Delete 111
    vector_remove(v, 999); // Find 999 and delete it

    printf("Final Size: %d\n", vector_size(v));

    vector_free(v);
    return 0;
}