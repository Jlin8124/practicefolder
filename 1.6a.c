#include <stdio.h>

#define MAX_LENGTH 15

int main(void)

{
    // we must first set some variables up that we can use later 
    // get the input
    // increment the inputs for the correct word length values
    // output the values using a for loop iterating through every word length possible
    // then printing the associated value with it

    // what variablles do we need, an array to store the count in 

    int c, i, j;
    int length = 0;
    int word_counts[MAX_LENGTH +1];

    // should i add values to it
    // do i add values to it during the for loop

    for (i = 0; i <= MAX_LENGTH; i++)
        word_counts[i] = 0;

    // set the array to 0

    while ((c = getchar()) != EOF) {

        if (c == ' ' || c == '\n' || c == '\t') {
            if (length > 0 && length <= MAX_LENGTH) {
                word_counts[length]++;
            }
            length = 0;
        }
        else {
            length++;
        }
    
    }
    // now we move on to printing

    if (length > 0 && length <= MAX_LENGTH)
        word_counts[length]++;
    
    for (i = 1; i <= MAX_LENGTH; i++) {
        printf("%2d ", i);
            for (j = 0; j < word_counts[i]; j++) {
                
                printf("*");

             
        }
        printf("\n");
    }
    
    
    return 0;
}

// mistakes were funky handling of the while loops, and if and else statements. Need to put length = 0;
// afterwards

// Need to count for EOF missing the last word because there is no blank space, tab, or newline
// Can put another if statement afterwards to catch that

// word_counts[i] this is an array that stores the value of the count at each indexed position
// We can run an outer loop of the numer and an inner loop of the counts to display horizontally the count

// Next up we have the vertical histogram component which is going to be tougher, it might be similar to mario in cs50



  