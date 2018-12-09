/* 
This header file performs all the computations required for the second order Runge-Kutta method
It performs this by obtaining the information from a textfile stored in an array of strucutres
*/

#define NMAX 8 
#define M 1988500e24
#define G 6.67e-11
#define COORD 2

// declaring a structure that contains all the properties of the planet's orbiting the Sun
typedef struct planet{
    char name[20];
    double mass;
    double pos[COORD];
    double vel[COORD];
    double accel[COORD];
    double est_pos[COORD];
    double est_vel[COORD];
    double est_accel[COORD];
} Planet;

// the read function reads data from the text file
void read(Planet *sptr) {
    FILE *fptr = NULL;
    fptr = fopen("data.txt", "r"); // opening the 'scores.txt' text file for reading

    if(fptr != NULL) {
        // the loop reads one line at a time from the text file "scores.txt"
        for(int i = 0; !feof(fptr); i++) {
            // the loop reads one line at a time from the text file "data.txt"
            fscanf(fptr, "%s %le", sptr[i].name, &sptr[i].mass);
            // the nested loop reads elements in from the text file into the 'pos' and 'vel' arrays in the structure
            for(int j = 0; j < 2; j++) {
                fscanf(fptr, "%le %le", &sptr[i].pos[j], &sptr[i].vel[j]);
            }
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

// this function converts all input time intervals/periods into seconds
double seconds(double time_value) {
    time_value *= 24.0 * 60.0 * 60.0;
    return time_value;
}

// evaluates and returns a planet's distance from the Sun
double distance(Planet *sptr, int i) {
    double r2 = pow(sptr[i].pos[0], 2) + pow(sptr[i].pos[1], 2);
    double r = sqrt(r2); // distance between the Sun and a planet

    return r;
}

// this predicts the planet's new position and velocity, for both x and y components
void predict(Planet *sptr, double dt, double r, int i) {
    // evaluating the initial x and y components of the planet's acceleration - negative as acting toward the Sun
    sptr[i].accel[0] = -(G * M * sptr[i].pos[0]) / (pow(r, 3));
    sptr[i].accel[1] = -(G * M * sptr[i].pos[1]) / (pow(r, 3));

    // estimating the x and y positions for the planet
    sptr[i].est_pos[0] = sptr[i].pos[0] + (sptr[i].vel[0] * (dt / 2.0));
    sptr[i].est_pos[1] = sptr[i].pos[1] + (sptr[i].vel[1] * (dt / 2.0));

    // estimating the x and y components for the velocity of the planet
    sptr[i].est_vel[0] = sptr[i].vel[0] + (sptr[i].accel[0] * (dt / 2.0));
    sptr[i].est_vel[1] = sptr[i].vel[1] + (sptr[i].accel[1] * (dt / 2.0));

    // estimating the x and y components for the acceleration of the planet
    sptr[i].est_accel[0] = -(G * M * sptr[i].est_pos[0]) / (pow(r, 3));
    sptr[i].est_accel[1] = -(G * M * sptr[i].est_pos[1]) / (pow(r, 3));
}

// the correct function updates the component positions and velocities
void correct(Planet *sptr, double dt, int i) {

    // evaluating the new updated x and y positions for the planet and storing them in the structure ready for the next iteration
    sptr[i].pos[0] += (sptr[i].vel[0] + sptr[i].est_vel[0]) * (dt / 2.0);
    sptr[i].pos[1] += (sptr[i].vel[1] + sptr[i].est_vel[1]) * (dt / 2.0);
    
    // now evaluating the new updated d and y velocities for the planet and storing them in the structure ready for the next iteration
    sptr[i].vel[0] += (sptr[i].accel[0] + sptr[i].est_accel[0]) * (dt / 2.0);
    sptr[i].vel[1] += (sptr[i].accel[1] + sptr[i].est_accel[1]) * (dt / 2.0);
}