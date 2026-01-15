#include <stdio.h>

int main(void)
{

    int blankincrement = 0;
    int blanktabs = 0;
    int blanknewlines = 0;

    int c = 0;
    int prev=0;

    while ((c = getchar()) != EOF)
    {

        if (c != ' ' || prev != ' ')
        {
            if (c == '\t')
                {
                    printf("\\t");
                }
            else if (c == '\b')
                {
                    printf("\b");
                }
            else if (c == '\\')
                {
                    printf("\\");
                }
            else
            {
                putchar(c);
            }
        }

        

        prev = c;
    }

    // So this concept involves creating a variable to hold the data from the previous characters.
    // Since you're reading character by chracter you can store it in prev
    // prev's job is to help you understand if the pervious character was a blank or not
    // so if it is blank you just don't print anythin

    // maybe you try an infinity loop of blanks


    return 0;

}

        //if (c = ' ')
        //{
        //    blankincrement++;
        //}
        //else if (c = '\t')
        //{
         //   blanktabs++;
        //}
        //else if (c = '\n')
        //{
         //   blanknewlines++;
        //}