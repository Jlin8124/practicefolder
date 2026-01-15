#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int* ptr = 0;
    ptr = malloc(sizeof(int)* 5);

    // how do I add values to the ptr i know how to add values to the array

    for (int i = 0; i < 5; i++) {

        *(ptr+i) = i;
        printf("%d\n", *(ptr+i));
    }

    free(ptr);
    return 0;
}