#include <stdio.h>
#include <math.h>
#include <time.h>

void reverse_array(int *arr, int size){
 
    int temp;
    temp = *arr;

    for (int i = 0; i < ((size+1)/2); i++) {
        temp = *(arr + i);

        *(arr + i) = *(arr + (size - (1+i)));
        *(arr + (size - (1+i))) = temp;

    }
    for (int i = 0; i < (size); i++)
    {
    
     
        printf("%d ", *(arr+i));
        // now my issue with 5 elements is
    }
    }

void reverse_array2(int *arr, int size) {
    
    int *start = arr;
    int *end = arr + size - 1;

    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;

    

    }

}





int main(void)
{
    int arr[] = {10, 20, 30, 40};
    int arr2[] = {1, 2, 3, 4, 5};

    int size = 1000000;
    int arr3[1000000];

    clock_t start = clock();

    reverse_array2(arr3, 1000000);

    clock_t end = clock();

    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    
    printf("Execution time: %f \n", time_spent);

    int *ptr = arr;
    
    for (int i =0; i < 4; i++){
        //printf("%d\n", arr[i]);
        //printf("%d\n", *(arr+i));
    }
    for (int i =0; i < 4; i++) {
        //printf("%d\n", *ptr);
       // ptr++; 
       // printf("%d\n", *ptr + 1);
        // okay so ptr is the memory address
        // *ptr is the value so we dont want to do *ptr++ because we don't want to increase the value
    }

    // Example 3: 2D Arrays pointer to pointer




    return 0;
}