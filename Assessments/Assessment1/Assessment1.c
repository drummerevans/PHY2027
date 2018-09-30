#include <stdio.h>
#include <math.h>
#define GRAV 9.81 // creating the constants required for the calculations
#define PI M_PI


int main() {
    float GRAVITY = 9.81, vel;

    printf("Enter a valid velocity: ");
    scanf("%f", &vel);
    printf("The velocity you entered was: %f\n", vel);

    printf("The acceleration due to gravity is: %.2f\n", GRAVITY);
    printf("%.2f\n", GRAV);

    float power = pow(10, 2); // pow() returns the first argument raised to the power of the second
    printf("10 ^ 2 = %.0f\n", power);

    printf("The value of pi is: %f", PI);

    return 0;
}
