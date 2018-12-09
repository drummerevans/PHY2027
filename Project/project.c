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

void output(Planet *sptr, int i);

int main() {
    Planet *struc_ptr = NULL; // declaring and initializing a structure pointer
    struc_ptr = (Planet *)malloc(NMAX * sizeof(Planet)); // allocating 8 spaces for our structure array of planets

    char array[20];

    read(struc_ptr);

    printf("Please enter a planet name within the solar system for mapping the motion around the Sun: ");
    scanf("%s", &array);

    // the loop iterates through all the planets in the structure until a match is found
    int j;
    do {
        if(strcmp(array, struc_ptr[j].name) == 0) {
        printf("Planet found.\n");
        output(struc_ptr, j);
        }
        j++;
    }
    while(j < NMAX);
     
    free(struc_ptr);

    return 0;
}

// this outputs the results calculated from the functions in the "mapper.h" header file to a text file "results.txt"
void output(Planet *sptr, int i) {
    FILE *result_ptr = NULL;
    result_ptr = fopen("results.txt", "w");

    double dt, T, freq, dump_time, time_until_dump;

    printf("Please input a value for the time step and time period in days, separated by a space: ");
    scanf("%lg %lg", &dt, &T);

    printf("\nNow, please select the frequency of the position outputs, in units of per days: ");
    scanf("%lg", &freq);

    dt = seconds(dt);
    T = seconds(T);
    dump_time = freq * dt;
    time_until_dump = dump_time;

    if(result_ptr != NULL) {
        // the for loop starts at time 0 and iterates until a given period
        // the time step is then increased by an amount dt and decreases to count on the data dump time by dt after each iteration
        for(double t = 0.0; t < T; t += dt, time_until_dump -= dt){
            double dist = distance(sptr, i);
            predict(sptr, dt, dist, i);
            correct(sptr, dt, i);
            if(time_until_dump <= 0.0) {
                time_until_dump = dump_time; // reseting the time until the next result output back to the original elapse time 
                fprintf(result_ptr, "%le %le\n", sptr[i].pos[0], sptr[i].pos[1]); // outputting position results to a text file once every 7 days
            }  
        }
    fclose(result_ptr);
    }
    else {
        printf("Unable to open results file.\n");
        exit(1);
    }     
}