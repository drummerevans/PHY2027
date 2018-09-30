#include <stdio.h>


int main() {
    double dvar1 = 1.23951, dvar2 = 5.39457;

    printf("Addition: \t\t%f + %f = %f\n", dvar1, dvar2, dvar1 + dvar2);
    printf("Subtraction: \t\t%f - %f = %f\n", dvar1, dvar2, dvar1 - dvar2);
    printf("Multiplication: \t%f * %f = %f\n", dvar1, dvar2, dvar1 * dvar2);
    printf("Division: \t\t%f / %f = %f\n", dvar1, dvar2, dvar1 / dvar2);

    float var1 = 1e-30, var2 = 1e40; // c doesn't care what value it is, but it will assign a value
                                    // python is an interpreted language, so it will puck up on over and under flows
    printf("\nAn underflow example is: %f\n", var1);
    printf("An overflow example is: %f\n", var2);

    return 0;
}