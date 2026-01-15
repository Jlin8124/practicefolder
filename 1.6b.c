#include <stdio.h>

// goal of the program is to display a histogram of the counts of each word of specific length

// set the proprocessors

#define MAX_LENGTH 15

int main(void)
{
    int c;
    int i = 0;
    int j = 0;
    int length = 0;
    int max_freq = 0;
    // int numsdigits[i];
    int word_count[MAX_LENGTH + 1];

    for (i = 0; i < MAX_LENGTH; i++)
        word_count[i] = 0;
    
    while ((c = getchar()) != EOF)
    {
        
        if (c == ' ' || c == '\n' || c == '\t') {
            if (length > 0 && length <= MAX_LENGTH)
                word_count[length]++;
        length = 0;
        }

        else
        {
            length++;
        
        }
        
    }
    if (length > 0 && length <= MAX_LENGTH) {
        word_count[length]++;   
    } 
    printf("%d ", word_count[0]);
    printf("%d ", word_count[1]);
    printf("%d ", word_count[2]);
    printf("%d ", word_count[3]);
    printf("%d ", word_count[4]);
    printf("\n");
    for (i = 1; i <= MAX_LENGTH; i++)
    {
        printf("%d ", i);

        for (j = 0; j < word_count[i]; j++)
        {
            printf("*");
        }
    printf("\n");
    }

    // for max frequency we need a loop to find it

    for (i = 1; i <= MAX_LENGTH; i++)
    {
        if (word_count[i] > max_freq)
        {
            max_freq = word_count[i];
        }
    }

    printf("Vertical Histogram\n");

    for (i = max_freq; i > 0; i--)
    {
        for (j = 1; j <= MAX_LENGTH; j++)
        {
            if (word_count[j] >= i)
            {
                printf("  * ");
            }
            else
            {
                printf("    ");
            }
        }
        printf("\n");
    }

    for (i = 0; i < MAX_LENGTH; i++)
    {
        printf("----");
    }
    printf("\n");
        for (i = 1; i <= MAX_LENGTH; i++)
    {
        printf("%3d ", i);
    }



    return 0;


}