/*
This program demonstrates some nice presentation for a switch statement
*/

#include <stdio.h>

int main() {
    int num;

    printf("Please enter a number 1, 2 or 3: ");
    scanf("%d", &num);

    switch(num) {
    case 1: case 2:
        printf("The value is either 1 or 2\n");
        break;
    case 3:
        printf("The value is 3\n");
        break;
    default:
        printf("The value is neither 1, 2 or 3\n");
    }

    return 0;
}