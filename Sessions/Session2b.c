#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define PI M_PI

float angle();


int main() {
    float hyp, final_angle;

    printf("Please enter the hypotoneuse of a right angled triangle: ");
    scanf("%f", &hyp);

    final_angle = angle();

    printf("The length of the adjacent side is: %f\n", hyp * cos(final_angle));
    printf("The length of the opposite side is: %f\n", hyp * sin(final_angle));

    return 0;
}

float angle() {
    float deg_angle, rad_angle;

    printf("Now, in degrees, enter an angle between 0 and 90: ");
    scanf("%f", &deg_angle);

    if(deg_angle < 0 || deg_angle > 90) {
        printf("\nInvalid angle entered!\n");
        printf("Please enter another angle between 0 and 90: ");
        scanf("%f", &deg_angle);
        angle(); // calling the function recursively in order to enter a valid angle
    }
    else {
        printf("The angle you entered was: %f\n", deg_angle);
        
        rad_angle = (PI / 180) * deg_angle; // converting the angle into radians
        printf("The angle in radians is now: %f\n", rad_angle);
        printf("The angle you entered was: %f\n", deg_angle);
    }
    
    return rad_angle;
}