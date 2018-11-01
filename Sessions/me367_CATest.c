/*
CA Test
01/11/2018
*/

#include <stdio.h>
#include <math.h>

#define NMAX 12 /* Defining a constant specifying the length of the character array for Question 1 */

float quadratic(float a, float b, float c);
void swap(int arr1[], int arr2[]); 

int main() {

    /* Question 1 */

    char sentence[NMAX];

    printf("Please enter in the sentence \'Tihuaenukas\': ");
    scanf("%s", sentence);

    printf("The odd letters from the word spell: ");
    
    /*
    The for loop will iterate through all the indivdual characters of the input word
    */
    for(int i = 0; i < NMAX; i++) {
        if(i % 2 == 0) {
            printf("%c", sentence[i]); /* printing the odd letters from the input word */
        }
    }
    
    /* Question 2 */

    int num1, num2, num3;

    printf("\nPlease enter in three different positive integer numbers, separated by spaces: ");
    scanf("%d %d %d", &num1, &num2, &num3);

    /*
    The while loop ensures three positive integers are entered
    */
    while(num1 < 0 || num2 < 0 || num3 < 0) {
        printf("!!!Invalid entry!!!");
    
        printf("\nPlease enter in three different positive integer numbers, separated by spaces: ");
        scanf("%d %d %d", &num1, &num2, &num3);
    }

    /*
    Several if statements are used in order to find and print the highest entered integer
    */
    if(num1 > num2 && num1 > num3) {
        printf("The highest number entered was: %d\n", num1);
    }
    if(num2 > num1 && num2 > num3) {
        printf("The highest number entered was: %d\n", num2);
    }
    if(num3 > num1 && num3 > num2) {
        printf("The highest number entered was: %d\n", num3);
    }
    else {
        printf("All the numbers entered are of equal value\n");
    }

    /* Question 3 */

    float coeff1, coeff2, coeff3;

    printf("Please enter in the coefficients, separated by spaces, (i.e. a, b and c) for a quadratic equation: ");
    scanf("%f %f %f", &coeff1, &coeff2, &coeff3);

    quadratic(coeff1, coeff2, coeff3);

    /*
    A print out of the results for when a = 1.0, b = 4.0 and c = 1.0 are included below:

    Please enter in the coefficients, separated by spaces, (i.e. a, b and c) for a quadratic equation: 1 4 1
    The solutions to the qudaratic equation are: -0.267949 and -3.732051
    */

    /* Question 4 */

    int iarray1[] = {1, 2, 3, 4}, iarray2[] = {5, 6, 7, 8};

    swap(iarray1, iarray2);

    /*
    A print out of the swapped arrays are below:

    Element[0] in iarray1 contains: 5
    Element[1] in iarray1 contains: 6
    Element[2] in iarray1 contains: 7
    Element[3] in iarray1 contains: 8
    Element[0] in iarray2 contains: 1
    Element[1] in iarray2 contains: 2
    Element[2] in iarray2 contains: 3
    Element[3] in iarray2 contains: 4
    */

    return 0;
}

/*
A function that solves a quadratic equation with the coefficients input by the user
*/

float quadratic(float a, float b, float c) {
    float x1 = 0, x2 = 0; /* declaring and initializing the solution variables to zero for the quadratic equation */

    /* 
    The if statements checks if the quadratic equation can be solved from the input coefficients
    */
    if(c >= b || a > b) { 
        printf("!!!Cannot be solved!!!\n");
        printf("Solution is a complex number!\n");
        return -1;
    }
    if(a == 0) {
        printf("!!!Cannot be solved!!!\n");
        printf("Infinity Error!\n");
        return -1;
    }

    x1 = (-b + sqrt(pow(b, 2) - (4 * a * c))) / (2 * a);
    x2 = (-b - sqrt(pow(b, 2) - (4 * a * c))) / (2 * a);

    printf("The solutions to the qudaratic equation are: %f and %f\n", x1, x2);

    return 0;
}

/*
A function that swaps two arrays of integer numbers
*/

void swap(int arr1[], int arr2[]) {
    int first[] = {0};
    int second[] = {0};
    int holder1 = 0, holder2 = 0; /* variables to contain the numbers from the arrays during the swapping process */
    
    /* 
    The loop will go through and swap the contents of the two arrays
    The 'holder' variable helps this tranisition
    */
    int i = 0;
    while(arr1[i]) {
        holder1 = arr1[i];
        holder2 = arr2[i];
        
        arr2[i] = holder1; 
        arr1[i] = holder2;
        i++;
    }

    int j = 0;
    while(arr1[j]) {
        printf("Element[%d] in iarray1 contains: %d\n", j, arr1[j]);
        j++;
    }

    int k = 0;
    while(arr1[k]) {
        printf("Element[%d] in iarray2 contains: %d\n", k, arr2[k]);
        k++;
    }
}