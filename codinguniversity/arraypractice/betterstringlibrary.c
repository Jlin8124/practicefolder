#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Goal of the program is to create something that makes a struct
// act like a string but grows automatically

#define MINIMUM_CAPACITY 16 // defining minimum capacity by 16

typedef struct {
    char* data;
    int size;
    int capacity;
} string;

string* create_vector(int actual_capacity) {

    int new_capacity = MINIMUM_CAPACITY;

    while (new_capacity < actual_capacity) {
        new_capacity = new_capacity * 2;
    }

    // so how we have to transfer the new_capacity to the string's capacity 
    // but it's giving me red error signs

    // we have to allocate memory now for the new_capacity
    string* new_data = malloc(sizeof(string));
    new_data->capacity = new_capacity;

    // we need a pointer to the char* no?

    char* newword = (char*)(malloc(sizeof(char) * new_capacity));
    new_data->data = newword;
    new_data->size = 0;
    return new_data;
}

void vector_push(string* v, int new_value) {

    char* new_data;
    
    if (v->size == v->capacity) {
        int new_capacity = v->capacity *2;
        v->capacity = new_capacity;
        char* new_data = realloc(v->data, sizeof(char) * new_capacity);
    

        if (new_data == NULL ) {
            return;
        }
        v->data = new_data;
    }   
        *(v->data + v->size) = new_value;

        v->size++;
}



// So should i use a string variable? or char variable?
// so string[size] = the characters

void resize(string* v) {

    // do i I need a resize value? don't I automatically have resizes in create vector and push
    // 
}

int main(void) {

    string* my_vector = create_vector(32);

    printf("%d \n", my_vector->size);

    printf("User Input: \n"); 

    char c;

    while ((c = getchar()) != '\n' && c != EOF) {
        vector_push(my_vector, c);
    }

    printf("%c \n", *(my_vector->data + 1));

    //okay so if I want to print out a specific character I have to use the * symbol
    // this derefences and gets the value at that address or point

   

    return 0; // always return after a int function return 0 is success


}

// mistakes changing it to || instead of && because if its a new line, or its EOF then its done
// need to set size in the create_vector to 0
// I need to figure out how to print the specific character of a string at position 0