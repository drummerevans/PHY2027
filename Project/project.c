/*
Project Option 2 for PHY2027
Date 14/12/2018
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "mapper.h" // this header file contains all the information and calculations required for determing the planetary motion

// declaring all the function prototypes used in this program contained in the "mapper.h" header file to complete the required calculations
void read(Planet *sptr);
double seconds(double time_value);
double distance(Planet *sptr, int i);
void predict(Planet *sptr, double dt, double r, int i);
void correct(Planet *sptr, double dt, int i);
void find(Planet *sptr, char planet_name[20]);

void output(Planet *sptr, int i);

int main() {
    Planet *struc_ptr = NULL; // declaring and initializing a structure pointer
    struc_ptr = (Planet *)malloc(NMAX * sizeof(Planet)); // allocating 8 spaces for our structure array of planets

    char array[20];
    int option = 1;

    read(struc_ptr);

    printf("Please enter a planet name within the solar system for mapping the motion around the Sun: ");
    scanf("%s", &array);

    find(struc_ptr, array);
    
    do {
        printf("\nWould you like to map another planet's orbit? ");
        printf("\n\t1. Yes");
        printf("\n\t2. No");
        printf("\nPlease enter 1 or 2: ");
        scanf("\n%d", &option);

        switch(option) {
            case 1:
                printf("Please enter a planet name within the solar system for mapping the motion around the Sun: ");
                scanf("%s", &array);
                find(struc_ptr, array);
                break;
            case 2:
                printf("Thank you and goodbye.\n");
                break;
            default:
                printf("Invalid entry.\n");
                break;
        }
    }
    while(option == 1);
       
    printf("\nIn order to view the plots, please run \'python plot.py\'.\n");
     
    free(struc_ptr);

    return 0;
}

void find(Planet *sptr, char planet_name[20]) {
    // the loop iterates through all the planets in the structure until a match is found
    for(int j = 0; j < NMAX; j++) {
        if(strcmp(planet_name, sptr[j].name) == 0) {
        printf("Planet found.\n");
        output(sptr, j);
        }
    }
}