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
    const float GRAVITY = 9.81; // declaring and initializing the acceleration due to gravity constant required for the calculations
    
    float vel = -1, angle = -1, rad_angle, distance, height;

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

    if(angle < 0 || angle > 180.0) {
        printf("\n\t!!!Invalid angle entered!!!\n");
        printf("\tNEGATIVE ANGLE ERROR\n");
        return NEGATIVE_ANGLE;
    }
    else {
        printf("\n\tThe angle you entered was: %f\n", angle);
        rad_angle = (M_PI / 180.0) * angle; // converting the angle into radians and intializing the 'rad_angle' variable as the result
    }

    distance = pow(vel, 2) * sin(2.0 * rad_angle) / GRAVITY; // equation giving the horizontal distance
    height = pow(vel, 2) * pow(sin(rad_angle), 2) / (2.0 * GRAVITY); // equation giving the maimum vertical height

    distance = fabs(distance); // to shield against printing -0.00 as distance

    printf("\n\tThe horizontal distance the projectile covered: %.2f\n", distance);
    printf("\tThe maximum vertical height the projectile reached was: %.2f\n", height);
    printf("\tAll evaluated to two decimal places.");

    return 0;
}

// A print out of the results for any valid velcoity and a launching angle of 0

// Please enter a valid velocity: 5

//         The velocity you entered was: 5

// Now, in degrees, please enter an angle between 0 and 180: 0

//         The angle you entered was: 0.000000

//         The horizontal distance the projectile covered: 0.00
//         The maximum vertical height the projectile reached was: 0.00
//         All evaluated to two decimal places.Matthews-MacBook-Pro:Assessment1 matthewevans$



// A print out of the results for any valid velcoity and a launching angle of 90

// Please enter a valid velocity: 60

//         The velocity you entered was: 60

// Now, in degrees, please enter an angle between 0 and 180: 90

//         The angle you entered was: 90.000000

//         The horizontal distance the projectile covered: 0.00
//         The maximum vertical height the projectile reached was: 183.49
//         All evaluated to two decimal places.Matthews-MacBook-Pro:Assessment1 matthewevans$


// A print out of the results for any valid velcoity and a launching angle of 45

// Please enter a valid velocity: 60

//         The velocity you entered was: 60

// Now, in degrees, please enter an angle between 0 and 180: 45

//         The angle you entered was: 45.000000

//         The horizontal distance the projectile covered: 366.97
//         The maximum vertical height the projectile reached was: 91.74
//         All evaluated to two decimal places.Matthews-MacBook-Pro:Assessment1 matthewevans$


// A print out of the results for a negative velocity and a any valid launching angle

// Please enter a valid velocity: -50

//         !!!Invalid velocity entered!!!
//         NEGATIVE VELOCITY ERROR
// Matthews-MacBook-Pro:Assessment1 matthewevans$