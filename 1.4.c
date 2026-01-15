#include <stdio.h>

int main(void)
{
    // So I need to get input first. After I get the input, read the input? 
    // Increment for every blank, tab or newline
    //

    int c;
    int incrementblank = 0, incrementtab = 0, incrementnewline = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
            {
                incrementblank++;
            }
        else if (c == '\n')
            {
                incrementnewline++;
            }
        else if (c == '\t')
            {
                incrementtab++;
            }
        putchar(c);


        // So i have to find out if there are multiple consecutive blanks
        // So i can try to read the character before it see if its a letter/number, and the one after it
        // I can try to see if there are 2 or more blanks in a row
        // Maybe you can do a loop that counts, and the moment it hits a actual letter it resets back to 0
        // 
    }
    printf("%d\n", incrementblank);
    printf("%d\n", incrementnewline);
    printf("%d\n", incrementtab);

    return 0;
}