#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define SUN_MASS 1988500e24
#define G 6.67e-11

typedef struct planet{
    char name[20];
    double mass;
    int period;
    double pos[2];
    double vel[2];
    double accel[2];
} Planet;

void read(Planet *sptr);
// double force(Planet *sptr);


int main() {;
    Planet *struc_ptr = NULL; // declaring and initializing a structure pointer
    struc_ptr = (Planet *)malloc(8 * sizeof(Planet)); // allocating 9 spaces for our structure array of planets

    FILE *result_ptr = NULL;
    result_ptr = fopen("results.txt", "w");

    read(struc_ptr);

    // initializing the initial values of the variables
    double x, y; // testing conditions for Earth first
    // printf("The value of vy for Earth is: %le\n", struc_ptr[2].pos[0]);
    double vx, vy;
    // printf("The value of vy for Earth is: %lf\n", struc_ptr[2].vel[1]);
    double ax = 0, ay = 0;


    for(int dt = 0; dt < 3; dt++) {
    x = struc_ptr[2].pos[0];
    y = struc_ptr[2].pos[1];
    // printf("The x coord is: %le\n", x);
    // printf("The y coord is: %le\n", y);
    vx = struc_ptr[2].vel[0];
    vy = struc_ptr[2].vel[1];

    double theta = (2 * M_PI * dt) / struc_ptr[2].period;
    double r2 = pow(x, 2) + pow(y, 2);
    // 'omega' is the angular speed of the planet around the Sun in rad/s
    double omega = sqrt(pow(vx, 2) + pow(vy, 2)) / sqrt(r2);
    printf("The value of theta is: %lf\n", theta);
    printf("The value of speed is: %le\n", omega);
    printf("The value of vy is: %lf\n", vy);
    printf("The value of r is: %lf\n", sqrt(r2));
    
    // breaking the component force calculations into two parts to prevent precedence errors
    double init_fx = (G * SUN_MASS * struc_ptr[2].mass) / r2; 
    double fx = (init_fx * x) / sqrt(r2);
    printf("The x force component is: %le\n", fx);
    double init_fy = (G * SUN_MASS * struc_ptr[2].mass) / r2; 
    double fy = (init_fy * y) / sqrt(r2);
    printf("The y force component is: %le\n", fy);

    // negative as the acceleartion always acts towards the centre of circular motion
    struc_ptr[2].accel[0] = -fx / (struc_ptr[2].mass); 
    printf("The x acceleration component is: %le\n", struc_ptr[2].accel[0]);
    struc_ptr[2].accel[1] = -fy / (struc_ptr[2].mass);
    printf("The y acceleration component is: %le\n", struc_ptr[2].accel[1]);

    struc_ptr[2].vel[0] = -omega * sqrt(r2) * sin(theta);
    printf("The initial value of vx is: %le\n", struc_ptr[2].vel[0]); 
    struc_ptr[2].vel[1] = omega * sqrt(r2) * cos(theta);
    printf("The initial value of vy is: %le\n", struc_ptr[2].vel[1]);

    struc_ptr[2].pos[0] += (struc_ptr[2].vel[0] * dt) + (struc_ptr[2].accel[0] * pow(dt, 2)) / 2;
    printf("The change in distance dx is: %le\n", struc_ptr[2].pos[0]);
    struc_ptr[2].pos[1] += (struc_ptr[2].vel[1] * dt) + (struc_ptr[2].accel[1] * pow(dt, 2)) / 2;
    printf("The change in distance dy is: %le\n", struc_ptr[2].pos[1]);

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
            fprintf(stdout, "Name: %s, Mass: %lekg, Period: %d days\n", sptr[i].name, sptr[i].mass, sptr[i].period);
            fprintf(stdout, "The planet position is, x = %lem y = %lem\n", sptr[i].pos[0], sptr[i].pos[1]);
            fprintf(stdout, "The planet velocity is, vx = %lem/s vy = %lem/s\n", sptr[i].vel[0], sptr[i].vel[1]);
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

// double force(Planet *sptr) {
//     double F;
//     if(strcmp())

// }

// void retrieve(Student *sptr, char array[CMAX]) {
//     printf("Name entered was: %s\n", array);
//     for(int i = 0; i < NMAX; i++) {
//         if(strcmp(array, sptr[i].name) == 0) {
//             printf("The final mark for %s is %f and the grade is %c\n", sptr[i].name, sptr[i].average_mark, sptr[i].grade);
//         }
//     } 
// }