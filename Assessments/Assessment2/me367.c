/*
Assessment 2 for PHY2027
Date 29/10/2018
*/

/*
This program evaluates the sum of a series of odd or even numbers.
The user makes a choice as to how many number in the series to add.
*/

#include <stdio.h>

#define NMAX 100

void create_array(int decision, int array[NMAX]);
int add_function(int amount, int array[NMAX]);


int main() {
    int option, nsum;
    int inums[NMAX] = {0};

    printf("\n\tWhat would you like to do?\n");
    printf("\n\t1. Find the series of odd integer numbers");
    printf("\n\t2. Find the series of even integer numbers\n");

    printf("\nPlease enter your option: ");
    scanf("%d", &option);
    
    while(option != 1 && option != 2) {
        printf("\n\t!!!Invalid entry!!!. Please try again.\n");

        printf("\n\tWhat would you like to do?\n");
        printf("\n\t1. Find the series of odd integer numbers");
        printf("\n\t2. Find the series of even integer numbers\n");

        printf("\nPlease enter a valid option: ");
        scanf("%d", &option);
    }

    create_array(option, inums);

    printf("\nNow, how many numbers from the series would you like to add?");
    printf("\nEnter a number from 1 to 100: ");
    scanf("%d", &nsum);

    while(nsum > 100 || nsum < 0) {
        printf("\n\t!!!Invalid entry!!!. Please try again.\n");

        printf("\nNow, how many numbers from the series would you like to add? ");
        printf("\nEnter a number from 1 to 100: ");
        scanf("%d", &nsum);
    }

    printf("\nThe total sum of your series is: %d\n", add_function(nsum, inums));
        
    return 0;
}

/*
If an invalid entry was entered the program will be stopped.
*/

void create_array(int decision, int array[NMAX]) {
    switch(decision) {
    case 1:
        printf("You chose to sum a series of odd numbers\n"); 
        for(int i = 0; i < NMAX; i++) {
            array[i] = (2 * i) + 1;
        }
        break;
    case 2:
        printf("You chose to sum a series of even numbers\n");
        for(int i = 0; i < NMAX; i++) {
            array[i] = (2 * i) + 2;
        }
        break;
    }
}

/*
This function will add a specified number of values, specified by the user.
This is achieved by using the array created from the previous function.
*/

int add_function(int amount, int array[NMAX]) {
    int sum = 0;
    for(int i = 0; i < amount; i++) {
        sum += array[i];
    }
    return sum;
}


// A print out of the results for a selection of incorrect inputs for the first while loop

// When a number other than 1 or 2 is entered:

//         What would you like to do?

//         1. Find the series of odd integer numbers
//         2. Find the series of even integer numbers

// Please enter your option: 7

//         !!!Invalid entry!!!. Please try again.

//         What would you like to do?

//         1. Find the series of odd integer numbers
//         2. Find the series of even integer numbers


// When a negative number is entered: 

//         What would you like to do?

//         1. Find the series of odd integer numbers
//         2. Find the series of even integer numbers

// Please enter your option: -4

//         !!!Invalid entry!!!. Please try again.

//         What would you like to do?

//         1. Find the series of odd integer numbers
//         2. Find the series of even integer numbers





// A print out of the results for a selection of incorrect inputs for the second while loop

// When a number greater than 100 is entered:

//         What would you like to do?

//         1. Find the series of odd integer numbers
//         2. Find the series of even integer numbers

// Please enter your option: 1
// You chose to sum a series of odd numbers

// Now, how many numbers from the series would you like to add?
// Enter a number from 1 to 100: 104

//         !!!Invalid entry!!!. Please try again.

// Now, how many numbers from the series would you like to add?
// Enter a number from 1 to 100:

// When a number less than 0 is entered:

//         What would you like to do?

//         1. Find the series of odd integer numbers
//         2. Find the series of even integer numbers

// Please enter your option: 2
// You chose to sum a series of even numbers

// Now, how many numbers from the series would you like to add?
// Enter a number from 1 to 100: -9

//         !!!Invalid entry!!!. Please try again.

// Now, how many numbers from the series would you like to add?
// Enter a number from 1 to 100:





// Performing the sum of the first 10 odd integer numbers

//         What would you like to do?

//         1. Find the series of odd integer numbers
//         2. Find the series of even integer numbers

// Please enter your option: 1
// You chose to sum a series of odd numbers

// Now, how many numbers from the series would you like to add?
// Enter a number from 1 to 100: 10

// The total sum of your series is: 100



// Performing the sum of the first 10 even integer numbers

//         What would you like to do?

//         1. Find the series of odd integer numbers
//         2. Find the series of even integer numbers

// Please enter your option: 2
// You chose to sum a series of even numbers

// Now, how many numbers from the series would you like to add?
// Enter a number from 1 to 100: 10

// The total sum of your series is: 110