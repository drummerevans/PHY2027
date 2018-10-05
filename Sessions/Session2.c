#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main() {
    float a, b;
    printf("Enter in the adjacent side of a right-angled triangle: ");
    scanf("%f", &a);

    printf("Now, enter in the opposite side of the right-angled triangle: ");
    scanf("%f", &b);

    printf("The value of the adjacent side entered is: %f\n", a);
    printf("The value of the opposite side enetered is: %f\n", b);

    if(a < 0 || b < 0) {
        printf("Invalid lengths entered!!!\n");
        return -1;
    }
    // else if((isalpha(a)) || (isalpha(b))) {
    //     printf("%c", isalpha(a));
    //     printf("Invalid lengths entered!!!\n");
    //     return -1;
    // }
    else {
        printf("The hypotenuse of the right-angled triangle to two decimal places figures is: %.2f\n", hypot(a, b));
    }

    return 0;
}