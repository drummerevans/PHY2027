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


int main() {
    const float GRAVITY = 9.81, PI = M_PI; // declaring and initializing the constants required for the calculations
    float vel, angle, rad_angle, distance, height;

    printf("Enter a valid velocity: ");
    scanf("%f", &vel);

    if(vel < 0) {
        printf("\t!!!Invalid velocity entered!!!\n");
        return 1;
    }
    else {
        printf("The velocity you entered was: %f\n", vel);
    }

    printf("\nNow, in degrees, enter an angle between 0 and 180: ");
    scanf("%f", &angle);

    if(angle < 0 || angle > 180) {
        printf("\t!!!Invalid angle entered!!!\n");
        return 1;
    }
    else {
        printf("The angle you entered was: %f\n", angle);
        
        rad_angle = (PI / 180) * angle; // converting the angle into radians
        printf("The angle in radians is now: %f\n", rad_angle);
        printf("The angle you entered was: %f\n", angle);
    }

    distance = (pow(vel, 2) * sin(2 * rad_angle)) / GRAVITY;
    height = pow(vel, 2) * pow(sin(rad_angle), 2) / (2 * GRAVITY);

    // float power = pow(10, 2); // pow() returns the first argument raised to the power of the second
    // printf("10 ^ 2 = %.0f\n", power);

    printf("The value of pi is: %f\n", PI);

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