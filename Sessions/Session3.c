/*
A program that calculates the voulme of various shapes
*/

#include <stdio.h>
#include <math.h>

void menu(void);
float vol_sph(float radius);
float vol_cyl(float radius, float height);
float vol_pyr(float length, float width, float height);

int main() {

    menu();
    return 0;
}

void menu(void) {
    int option;
    float r, h, l, w;

    printf("\n\tWhat would you like to do?\n");
    printf("\n\t1. Find the volume of a sphere");
    printf("\n\t2. Find the volume of a cylinder");
    printf("\n\t3. Find the volume of a pyramid");
    printf("\n\t4. Nothing!\n");

    scanf("%d", &option);

    switch(option) {
    case 1:
        printf("Enter in a radius: ");
        scanf("%f", &r);
        printf("The volume of the sphere is: %f\n", vol_sph(r));
        break;
    case 2:
        printf("Enter in a radius and height, separated by a space: ");
        scanf("%f %f", &r, &h); 
        printf("The volume of the cylinder is: %f\n", vol_cyl(r, h));
        break;
    case 3:
        printf("Enter in a length, width and height, separated by spaces: ");
        scanf("%f %f %f", &l, &w, &h);  
        printf("The volume of the pyramid is: %f\n", vol_pyr(l, w, h));
        break;
    default:
        printf("You selected not to a calculate anything\n"); 
        return;
    }
}

float vol_sph(float radius) {
    float volume;
    volume = (4.0/3 * M_PI) * pow(radius, 3);
    return volume;
}

float vol_cyl(float radius, float height) {
    float volume;
    volume = M_PI * pow(radius, 2) * height;
    return volume;
}

float vol_pyr(float length, float width, float height) {
    float volume;
    volume = (length * width * height) / 3;
    return volume;
}

