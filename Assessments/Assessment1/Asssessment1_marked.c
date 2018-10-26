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

/*
Very good program! only a few minor flaws. Well done!!!

Good header and accurate comments which are nice and concise. Would like too see in future a header comment for main(). Each function should have its own comment explaining the primary purpose and method. (In this case you have only one function but in future)
too many #include....you only need two of them!
Remember too keep the right types, ints, floats, doubles, etc don't mix! Also get used to using doubles rather than floats...better for scientific programing.
I like the use of error constants but perhaps over the top for this program, dont give yourself more work than you need, dont overcomplicate! bravity is your friend.
Use #define for physical constants you want to use... eg. #define GRAVITY 9.81.
Also floats work to 8 decimal places on a 64 machine 7 on a 32. doubles work to 16! using only 2 decimal places for g seems a little sparing.
*/
int main() {
    const int NEGATIVE_VELOCITY = -1, NEGATIVE_ANGLE = -1, SPEED_OF_LIGHT_ERROR = 1; // declaring and intializing error message constants
    const float GRAVITY = 9.81; // declaring and initializing the acceleration due to gravity constant required for the calculations

    float vel = -1, angle = -1, rad_angle, distance, height; //good variable names

    printf("\nPlease enter a valid velocity: ");
    scanf("%f", &vel);

    if(vel < 0) {//note: comparing different types int and float. should read if(vel < 0.0)
        printf("\n\t!!!Invalid velocity entered!!!\n");
        printf("\tNEGATIVE VELOCITY ERROR\n");
        return NEGATIVE_VELOCITY;
    }
    else if(vel > 3e8) {//note: int and float comparison as above use 3.0e8
        printf("\n\t!!!Invalid velocity entered!!!\n");
        printf("\tSPEED OF LIGHT ERROR\n");
        return SPEED_OF_LIGHT_ERROR;
    }
    else {
        printf("\n\tThe velocity you entered was: %g\n", vel);
    }

    printf("\nNow, in degrees, please enter an angle between 0 and 180: ");
    scanf("%f", &angle);

    if(angle < 0 || angle > 180.0) {//note: int and flat comparison use 0.0
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

/*
good calcuations nice and concise. Improvements: pow(double,double) expects two doubles as arguement so don't use ints as input. eg 2.0 not 2
use of fabs is good but you loose infomation here so would have prefered to have seen it produce negative distances.
*/
    printf("\n\tThe horizontal distance the projectile covered: %.2f\n", distance);
    printf("\tThe maximum vertical height the projectile reached was: %.2f\n", height);//good!
    printf("\tAll evaluated to two decimal places."); //why only 2? perhaps add in the ability to change this... ie use a #define to set the precision.

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
