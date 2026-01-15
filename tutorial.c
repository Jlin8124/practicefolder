#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

int main(void)
{
    printf("hello\n");
    

    float fahr, celc;
    float upper, lower, step;

    upper = 300;
    lower = 0;
    step = 20;

    fahr = lower;
    
    while (fahr <= upper)
    {

        celc = (5.0/9.0) * (fahr-32);
        printf("%3.3f %6.0f\n", celc, fahr);
        fahr = fahr + step;
    }

    


    for (fahr = 300; fahr >= 0 && fahr <= 300; fahr = fahr - 20)
    {
        printf("%3.0f %6.0f\n", fahr, (5.0/9.0)*(fahr-32));

    }


    int c;
    long nc;
    nc = 0;
    while ((c = getchar()) != EOF)
    {
        
        // printf("This is loop x %d\n", getchar() != EOF);
        
        putchar(c);
        ++nc;
        
    }
    printf("%ld\n", nc); 
    printf("%d", c == EOF);

    return 0;


}