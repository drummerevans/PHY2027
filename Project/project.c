#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "mapper.h"

int main() {
    Planet *struc_ptr = NULL; // declaring and initializing a structure pointer
    struc_ptr = (Planet *)malloc(NMAX * sizeof(Planet)); // allocating 8 spaces for our structure array of planets

    char array[20];

    read(struc_ptr);

    printf("Please enter a planet name within the solar system for mapping the motion around the Sun: ");
    scanf("%s", &array);

    for(int i = 0; i < NMAX; i++) {
        if(strcmp(array, struc_ptr[i].name) == 0) {
            printf("Planet found.\n");
            output(struc_ptr, i);
        }
    }  
    
    free(struc_ptr);

    return 0;
}