#include <stdio.h>
#include <math.h>

#define NMAX 100
#define NUMBERS 4

float average(float narray[NMAX]);
float std_dev(float narray[NMAX], float mean_val);


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

    float mean, deviation;
    float narray[NUMBERS];

    printf("Please input four numbers you would like to take the average of and press enter after each entry: \n");
   
    mean = average(narray);
    printf("The average of the four numbers is: %f\n", mean);

    deviation = std_dev(narray, mean);
    printf("The standard deviation of the four numbers is: %f\n", deviation);
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

float std_dev(float narray[NUMBERS], float mean_val) {
    float ndiff[NUMBERS];
    float pre_result = 0, result;
    for(int i = 0; i < NUMBERS; i++) {
        ndiff[i] = pow((narray[i] - mean_val), 2);
    }
    for(int i = 0; i < NUMBERS; i++) {
        pre_result += ndiff[i];
    }

    result = pre_result / (NUMBERS - 1);
    
    return result;
}