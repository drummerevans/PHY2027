/* 
Assessment 1 for PHY2027
Date...
*/

/*
This program computes the maximum vertical height and horizontal range.
For a given velocity and launching angle entered by the user.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


#define GRAV 9.81 // creating the constants required for the calculations
#define PI M_PI

float veclocity();
float angle(); // defining a function prototype for computing a valid angle


int main() {
    const float GRAVITY = 9.81;
    float vel, launch_angle;

    vel = veclocity();
    launch_angle = angle();

    // printf("The acceleration due to gravity is: %.2f\n", GRAVITY);
    // printf("%.2f\n", GRAV);

    // float power = pow(10, 2); // pow() returns the first argument raised to the power of the second
    // printf("10 ^ 2 = %.0f\n", power);

    printf("The value of pi is: %f", PI);

    return 0;

    // print out terminal test values and results here!!!
}

float veclocity() {
    float vel1;
    int option;

    printf("Enter a valid velocity: ");
    scanf("%f", &vel1);
    printf("The velocity you entered was: %f\n", vel1);

    if(vel1 < 0) {
        printf("Invalid velocity entered!!!\n");
        printf("\n\tWould you like to try again?");
        printf("\n\tOption 1: Enter 1 to try again.");
        printf("\n\tOption 2: Enter 2 to end the program.\n");
        scanf("%d", &option);

        switch(option) {
            case 1: 
                veclocity();
                break;
            case 2:
                return 1;
                break;
            default: 
                printf("Program terminated.\n"); return 1;
                break; 
        }
    }
    else {
        printf("The velocity entered was: %f", vel1);
    }
    return vel1;
}

float angle() {
    float deg_angle, rad_angle;

    printf("\nNow, in degrees, enter an angle between 0 and 180: ");
    scanf("%f", &deg_angle);

    if(deg_angle < 0 || deg_angle > 180) {
        printf("\nInvalid angle entered!\n");
        printf("Please enter another angle between 0 and 180: ");
        scanf("%f", &deg_angle);
        angle(); // calling the function recursively in order to enter a valid angle
    }
    // else if(!isdigit(deg_angle)) {
    //     printf("\nInvalid angle entered!\n");
    //     return -1;
    // }
    else {
        printf("The angle you entered was: %f\n", deg_angle);
        
        rad_angle = (PI / 180) * deg_angle; // converting the angle into radians
        printf("The angle in radians is now: %f\n", rad_angle);
        printf("The angle you entered was: %f\n", deg_angle);
    }
    
    return rad_angle;
}
