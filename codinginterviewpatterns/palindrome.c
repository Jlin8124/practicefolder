#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

bool is_palindrome(const char stringbeingtested[]) {

    int left = 0;
    int right = strlen(stringbeingtested) - 1;
    // I need to get the end of the string or the length of the string
    // We want to or could remove all blank spaces, and alphanumerical characters
    // You can either iterate through the full thing and delete everything
    // Or you can use a two pointer and just increment the left or right only if its a non alphanumerical character
    // implement a while loop that keeps going while right is bigger than left

    while (right > left) {

        while (isalnum(stringbeingtested[left]) == false) {
            left += 1;
        }
        while (isalnum(stringbeingtested[right]) == false) {
            right -= 1;
        
        printf("%c %c\n", stringbeingtested[left], stringbeingtested[right]);
        }
        if (stringbeingtested[left] != stringbeingtested[right]) {
            return false;
        }
        left += 1;
        right -= 1;
    }
    return true;

    // my thinking is that you can check if its alphanumerical by 1-9 and a-z and A-z using their ascii numbers
    // Set up an if statement here within here if its true to print out true
    // if its false to print out false
}

int main(void) {

    char stringtestfirst[] = "a dog! a panic in a pagoda.";
    char stringtestsecond[] = "boaob";

    printf("%s \n", stringtestfirst);
    printf("%ld \n", strlen(stringtestfirst));

    // I don't know how to create a string in c

    // How do you check if a string is palindrome which means the same front and backwards
    // We can use a two pointer method 
    // I want to start from left and right create a function?

    // We need to output true or false at the end
    
    bool result = is_palindrome(stringtestsecond);


    printf("Is it a palindrome? %s\n", result ? "true" : "false");
    

    return 0;
}

// KEY CONCEPTS

// Need to check if letters or characters match. Need to use two pointer method to increment
// Need to keep incrementing left +1 and right -1 if its not alphanumerical
// Need to return true or false depending on if they match or not


// Edge case testing
// What happens when its an odd number then it doesn't matter what the middle value is