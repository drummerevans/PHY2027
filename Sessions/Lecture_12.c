#include <stdio.h>

#define NMAX 100
#define NUMBERS 4

float average(float narray[NMAX]);
void std_dev(float a, float b, float c, float d, float result1);


int main() {

    /*
    This is question 1
    */

    char name[NMAX];

    printf("Please enter your name: ");

    scanf("%[^\n]s", name);

    printf("Your name is: %s\n", name);

    /*
    This is question 2
    */

    float mean;
    float narray[NUMBERS];

    printf("Please input four numbers you would like to take the average of and press enter after each entry: \n");
   
    mean = average(narray);
    printf("The average of the four numbers is: %f\n", mean);

    return 0;
}

float average(float narray[NUMBERS]) {
    float element, nsum = 0, result;
    for(int i = 0; i < NUMBERS; i++) {
        scanf("%f", &element);
        narray[i] = element;
    }

    for(int i = 0; i < NUMBERS; i++) {
        nsum += narray[i];
    }

    result = nsum / NUMBERS;
    return result;
}

// void std_dev(float a, float b, float c, float d, float result1) {
//     for(int i = 0; i < 4; i++) {

//     }

// }