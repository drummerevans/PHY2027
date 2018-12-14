/* 
This header file performs all the computations required for the second order Runge-Kutta method.
It performs this by obtaining the information from a textfile "data.txt" and stores this in an array of structures.
These functions are then all called from the "project.c" program file.
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
    fptr = fopen("data.txt", "r"); // opening the "data.txt" text file for reading

    if(fptr != NULL) {
        // the loop reads one line at a time from the text file "data.txt"
        for(int i = 0; !feof(fptr); i++) {
            // the loop reads one line at a time from the text file "data.txt"
            fscanf(fptr, "%s %lg", sptr[i].name, &sptr[i].mass);
            // the nested loop reads elements in from the text file into the 'pos' and 'vel' arrays in the structure
            for(int j = 0; j < 2; j++) {
                fscanf(fptr, "%lg %lg", &sptr[i].pos[j], &sptr[i].vel[j]);
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

// this outputs the results calculated from the functions in the "mapper.h" header file to a specified text file
void output(Planet *sptr, int i) {
    FILE *result_ptr = NULL;
    char file[50];

    printf("\nPlease enter a text file (including the .txt extension) to store the output data: ");
    scanf("%s", file);
    result_ptr = fopen(file, "w");

    double dt, T, freq, dump_time, time_until_dump;

    printf("\nPlease input a value for the time step and time period in days, separated by a space: ");
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
                fprintf(result_ptr, "%lg %lg\n", sptr[i].pos[0], sptr[i].pos[1]); // outputting position results to a text file once every 7 days
            }  
        }
    fclose(result_ptr);
    }
    else {
        printf("Unable to open results file.\n");
        exit(1);
    }     
}