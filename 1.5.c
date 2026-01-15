#include <stdio.h>

#define IN 1
#define OUT 0 

int main(void)
{
    int c, nl, nw, nc, state;
    
    state = OUT;
    
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF)
    {
        nc++;
        putchar(c);
           
        if (c == '\n')
        {
            nl++;
        }
        if (c == ' ' || c == '\n' || c == '\t')
        {
            state = OUT;
            // printf("\n");
        }

        else if (state == OUT)
        {
            state = IN;
            nw++;
            
        }
    }
    printf("%d %d %d\n", nl, nw, nc);
}

// most likely to encounter inputs, what about words? what about past the word limit or memory storage limit
// 