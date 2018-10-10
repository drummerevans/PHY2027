/* 
Assessment 1 for PHY2027
Date...
*/

/*
This program computes the maximum vertical height and horizontal range of a projectile.
For a given velocity and launching angle entered by the user.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


int main() {
    const int NEGATIVE_VELOCITY = -1, NEGATIVE_ANGLE = -1, SPEED_OF_LIGHT_ERROR = 1; // declaring and intializing error message constants
    const float GRAVITY = 9.81, PI = M_PI; // declaring and initializing the constants required for the calculations
    float vel = -1, angle = -1, rad_angle, distance, height, testVel = -1;

    printf("\nPlease enter a valid velocity: ");
    scanf("%f", &vel);

    if(vel < 0) {
        printf("\n\t!!!Invalid velocity entered!!!\n");
        printf("\tNEGATIVE VELOCITY ERROR\n");
        return NEGATIVE_VELOCITY;
    }
    else if(vel > 3e8) {
        printf("\n\t!!!Invalid velocity entered!!!\n");
        printf("\tSPEED OF LIGHT ERROR\n");
        return SPEED_OF_LIGHT_ERROR; 
    }
    else {
        printf("\n\tThe velocity you entered was: %g\n", vel);
    }

    printf("\nNow, in degrees, please enter an angle between 0 and 180: ");
    scanf("%f", &angle);

    if(angle < 0 || angle > 180) {
        printf("\n\t!!!Invalid angle entered!!!\n");
        printf("\tNEGATIVE ANGLE ERROR\n");
        return NEGATIVE_ANGLE;
    }
    else {
        printf("\n\tThe angle you entered was: %f\n", angle);
        
        rad_angle = (PI / 180) * angle; // converting the angle into radians and intializing the 'rad_angle' variable as the result
        printf("\n\tThe angle in radians is now: %f\n", rad_angle);
        printf("\n\tThe angle you entered was: %f\n", angle);
    }

    distance = pow(vel, 2) * sin(2 * rad_angle) / GRAVITY; // equation giving the horizontal distance
    height = pow(vel, 2) * pow(sin(rad_angle), 2) / (2 * GRAVITY); // equation giving the maimum vertical height

    distance = abs(distance); // to shield against printing -0.00 as distance

    printf("\n\tThe horizontal distance the projectile covered: %.2f\n", distance);
    printf("\tThe maximum vertical height the projectile reached was: %.2f\n", height);
    printf("\tAll evaluated to two decimal places.");


    return 0;

    // print out terminal test values and results here!!!
}

// float veclocity() {
//     float vel1;
//     int option;

//     printf("Enter a valid velocity: ");
//     scanf("%f", &vel1);
//     printf("The velocity you entered was: %f\n", vel1);

//     if(vel1 < 0) {
//         printf("Invalid velocity entered!!!\n");
//         printf("\n\tWould you like to try again?");
//         printf("\n\tOption 1: Enter 1 to try again.");
//         printf("\n\tOption 2: Enter 2 to end the program.\n");
//         scanf("%d", &option);

//         switch(option) {
//             case 1: 
//                 veclocity();
//                 break;
//             case 2:
//                 return 1;
//                 break;
//             default: 
//                 printf("Program terminated.\n"); return 1;
//                 break; 
//         }
//     }
//     else {
//         printf("The velocity entered was: %f", vel1);
//     }
//     return vel1;
// }

// float angle() {
//     float deg_angle, rad_angle;

//     printf("\nNow, in degrees, enter an angle between 0 and 180: ");
//     scanf("%f", &deg_angle);

//     if(deg_angle < 0 || deg_angle > 180) {
//         printf("\nInvalid angle entered!\n");
//         printf("Please enter another angle between 0 and 180: ");
//         scanf("%f", &deg_angle);
//         angle(); // calling the function recursively in order to enter a valid angle
//     }
//     // else if(!isdigit(deg_angle)) {
//     //     printf("\nInvalid angle entered!\n");
//     //     return -1;
//     // }
//     else {
//         printf("The angle you entered was: %f\n", deg_angle);
        
//         rad_angle = (PI / 180) * deg_angle; // converting the angle into radians
//         printf("The angle in radians is now: %f\n", rad_angle);
//         printf("The angle you entered was: %f\n", deg_angle);
//     }
    
//     return rad_angle;
// }