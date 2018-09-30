#include <stdio.h>
#include <math.h>
#define GRAV 9.81


int main() {
    float GRAVITY = 9.81;
    float vel;

    printf("Enter a valid velocity: ");
    scanf("%f", &vel);
    printf("The velocity you entered was: %f\n", vel);

    printf("The acceleration due to gravity is: %.2f\n", GRAVITY);
    printf("%.2f\n", GRAV);

    float power = pow(10, 2); // powe() returns the first argument raised to the power of the second
    printf("10 ^ 2 = %.0f\n", power);

    return 0;
}