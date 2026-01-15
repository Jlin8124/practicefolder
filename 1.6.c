#include <stdio.h>

int main(void)
{
    int c, i, nwhite, nother;
    int ndigit[10];

    nwhite = nother = 0;
    for (i = 0; i < 10; i++) {
        ndigit[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\b') {
            nwhite++;
        } 
        else if (c >= '0' && c <= '9') {
            ndigit[c - '0']++;
        }
        else 
            nother++;
    }
    printf("%d %d ", nwhite, nother);

    for (i = 0; i <10; i++) {
        printf("%d ", ndigit[i]);
    }

}