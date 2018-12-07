#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

// defining the Sun mass and universal gravitational constant values
#define M 1988500e24
#define G 6.67e-11

typedef struct planet{
    char name[20];
    double mass;
    double pos[2];
    double vel[2];
    double accel[2];
    double est_pos[2];
    double est_vel[2];
    double est_accel[2];
} Planet;

void read(Planet *sptr);
double distance(Planet *sptr);
void predict(Planet *sptr, double dt, double r);
void correct(Planet *sptr, double dt);


int main() {
    Planet *struc_ptr = NULL; // declaring and initializing a structure pointer
    struc_ptr = (Planet *)malloc(8 * sizeof(Planet)); // allocating 8 spaces for our structure array of planets

    FILE *result_ptr = NULL;
    result_ptr = fopen("results.txt", "w");

    double dt = 86400.0;
    double T = 4e7;
    double dump_time = 7 * dt;
    double time_until_dump = dump_time;

    read(struc_ptr);
    
    // the for loop starts at time 0 and iterates until a given period
    // the time step is then increased by an amount dt and and dumps the values for the positions every 7 days
    for(double t = 0.0; t < T; t += dt, time_until_dump -= dt){
        printf("The current time is: %lg    time unti dump: %lg\n", t, time_until_dump);
        // if(time_until_dump <= 0.0) {
        //     time_until_dump = dump_time; // outputting result every 7 days
        //     fprintf(result_ptr, "%le %le\n", struc_ptr[2].pos[0], struc_ptr[2].pos[1]);
        //     printf("Dumping\n");
        // }
        // else {
        //     printf("Unable to open results file.\n");
        //     return 1;
        // }
        double dist = distance(struc_ptr);
        predict(struc_ptr, dt, dist);
        correct(struc_ptr, dt);

        if(result_ptr != NULL) {
            printf("Results file opened.\n");
            fprintf(result_ptr, "%le %le\n", struc_ptr[2].pos[0], struc_ptr[2].pos[1]);
        }
        else {
            printf("Unable to open results file.\n");
            return 1;
        }
    }

    

    fclose(result_ptr);
    free(struc_ptr);

    return 0;
}

// the read function reads data from the text file
void read(Planet *sptr) {
    FILE *fptr = NULL;
    fptr = fopen("data.txt", "r"); // opening the 'scores.txt' text file for reading

    if(fptr != NULL) {
        // the loop reads one line at a time from the text file "scores.txt"
        for(int i = 0; !feof(fptr); i++) {
            // the loop reads one line at a time from the text file "data.txt"
            fscanf(fptr, "%s %le %d", sptr[i].name, &sptr[i].mass, &sptr[i].period);
            // the nested loop reads elements in from the text file into the 'pos' and 'vel' arrays in the structure
            for(int j = 0; j < 2; j++) {
                fscanf(fptr, "%le %le", &sptr[i].pos[j], &sptr[i].vel[j]);
            }
            // fprintf(stdout, "Name: %s, Mass: %lekg, Period: %d days\n", sptr[i].name, sptr[i].mass, sptr[i].period);
            // fprintf(stdout, "The planet position is, x = %lem y = %lem\n", sptr[i].pos[0], sptr[i].pos[1]);
            // fprintf(stdout, "The planet velocity is, vx = %lem/s vy = %lem/s\n", sptr[i].vel[0], sptr[i].vel[1]);
        }
        // closing the text file after the data has been scanned into the relevant structures
        fclose(fptr); 
        }
        // exits the program if there is a problem with opening the specified text file
        else {
            printf("Unable to open text file\n");
            exit(1); 
        }
    }

// evaluates and returns a planet's distance from the Sun
double distance(Planet *sptr) {
    double r2 = pow(sptr[2].pos[0], 2) + pow(sptr[2].pos[1], 2);
    double r = sqrt(r2); // distance between the Sun and a planet

    return r;
}

void accelerate(Planet *sptr) {
    sptr[2].accel[0] = -(G * M * )
}

// this predicts the planet's new position and velocity, for both x and y components
void predict(Planet *sptr, double dt, double r) {
    // evaluating the initial x and y components of the planet's acceleration - negative as acting toward the Sun
    sptr[2].accel[0] = -(G * M * sptr[2].pos[0]) / (pow(r, 2) * r);
    sptr[2].accel[1] = -(G * M * sptr[2].pos[1]) / (pow(r, 2) * r);

    // printf("\nThe initial ax = %le and initial ay = %le\n", sptr[2].accel[0], sptr[2].accel[1]);

    // estimating the x and y positions for the planet
    sptr[2].est_pos[0] = sptr[2].pos[0] + (sptr[2].vel[0] * (dt / 2));
    sptr[2].est_pos[1] = sptr[2].pos[1] + (sptr[2].vel[1] * (dt / 2));

    // printf("The estimated x and y positions are: %le and %le\n", sptr[2].est_pos[0], sptr[2].est_pos[1]);

    // now estimating the x and y components for the velocity of the planet
    sptr[2].est_vel[0] = sptr[2].vel[0] + (sptr[2].accel[0] * (dt / 2));
    sptr[2].est_vel[1] = sptr[2].vel[1] + (sptr[2].accel[1] * (dt / 2));

    // printf("The estimated x and y velocities are: %le and %le\n", sptr[2].est_vel[0], sptr[2].est_vel[1]);

    sptr[2].est_accel[0] = -(G * M * sptr[2].est_pos[0]) / (pow(r, 2) * r);
    sptr[2].est_accel[1] = -(G * M * sptr[2].est_pos[1]) / (pow(r, 2) * r);

    // printf("\nThe esitmated ax = %le and estimated ay = %le\n", sptr[2].est_accel[0], sptr[2].est_accel[1]);
}

// the correct function updates the component positions and velocities
void correct(Planet *sptr, double dt) {

    // evaluating the new updated x and y positions for the planet and storing them in the structure ready for the next iteration

    // printf("Initial x position is: %le\n", sptr[2].pos[0]);
    // printf("Initial vx velocity is: %le\n", sptr[2].vel[0]);
    // printf("Estimated vx veolcity is: %le\n", sptr[2].est_vel[0]);
    sptr[2].pos[0] += (sptr[2].vel[0] + sptr[2].est_vel[0]) * (dt / 2);
    
    // printf("Initial y position is: %le\n", sptr[2].pos[1]);
    // printf("Initial vy velocity is: %le\n", sptr[2].vel[1]);
    // printf("Estimated vy veolcity is: %le\n", sptr[2].est_vel[1]);
    sptr[2].pos[1] += (sptr[2].vel[1] + sptr[2].est_vel[1]) * (dt / 2);
    
    printf("%le %le\n", sptr[2].pos[0], sptr[2].pos[1]);


    // printf("Initial vx velocity is: %le\n", sptr[2].vel[0]);
    // printf("Initial ax accleration is: %le\n", sptr[2].accel[0]);
    // printf("Estimated ax acceleration is: %le\n", sptr[2].est_accel[0]);
    sptr[2].vel[0] += (sptr[2].accel[0] + sptr[2].est_accel[0]) * (dt / 2);
    sptr[2].vel[1] += (sptr[2].accel[1] + sptr[2].est_accel[1]) * (dt / 2);

    // printf("The new planetary velocities are vx = %le and vy = %le\n", sptr[2].vel[0], sptr[2].vel[1]);
}