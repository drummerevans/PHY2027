// declaring the function prototypes, where the int i argument represents the planet number (i.e. planet) in the planet array
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
            // fprintf(stdout, "Name: %s, Mass: %lekg, Period: %d days\n", sptr[i].name, sptr[i].mass);
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

// this function converts all input time intervals/periods into seconds
double seconds(double time_value) {
    time_value *= 24 * 60 * 60;
    return time_value;
}

// evaluates and returns a planet's distance from the Sun
double distance(Planet *sptr, int i) {
    double r2 = pow(sptr[i].pos[0], 2) + pow(sptr[2].pos[1], 2);
    double r = sqrt(r2); // distance between the Sun and a planet

    return r;
}



// this predicts the planet's new position and velocity, for both x and y components
void predict(Planet *sptr, double dt, double r, int i) {
    // evaluating the initial x and y components of the planet's acceleration - negative as acting toward the Sun
    sptr[i].accel[0] = -(G * M * sptr[i].pos[0]) / (pow(r, 2) * r);
    sptr[i].accel[1] = -(G * M * sptr[i].pos[1]) / (pow(r, 2) * r);

    // printf("\nThe initial ax = %le and initial ay = %le\n", sptr[2].accel[0], sptr[2].accel[1]);

    // estimating the x and y positions for the planet
    sptr[i].est_pos[0] = sptr[i].pos[0] + (sptr[i].vel[0] * (dt / 2));
    sptr[i].est_pos[1] = sptr[i].pos[1] + (sptr[i].vel[1] * (dt / 2));

    // printf("The estimated x and y positions are: %le and %le\n", sptr[2].est_pos[0], sptr[2].est_pos[1]);

    // estimating the x and y components for the velocity of the planet
    sptr[i].est_vel[0] = sptr[i].vel[0] + (sptr[i].accel[0] * (dt / 2));
    sptr[i].est_vel[1] = sptr[i].vel[1] + (sptr[i].accel[1] * (dt / 2));

    // printf("The estimated x and y velocities are: %le and %le\n", sptr[2].est_vel[0], sptr[2].est_vel[1]);

    // estimating the x and y components for the acceleration of the planet
    sptr[i].est_accel[0] = -(G * M * sptr[i].est_pos[0]) / (pow(r, 2) * r);
    sptr[i].est_accel[1] = -(G * M * sptr[i].est_pos[1]) / (pow(r, 2) * r);

    // printf("\nThe esitmated ax = %le and estimated ay = %le\n", sptr[2].est_accel[0], sptr[2].est_accel[1]);
}

// the correct function updates the component positions and velocities
void correct(Planet *sptr, double dt, int i) {

    // evaluating the new updated x and y positions for the planet and storing them in the structure ready for the next iteration

    // printf("Initial x position is: %le\n", sptr[2].pos[0]);
    // printf("Initial vx velocity is: %le\n", sptr[2].vel[0]);
    // printf("Estimated vx veolcity is: %le\n", sptr[2].est_vel[0]);
    sptr[i].pos[0] += (sptr[i].vel[0] + sptr[i].est_vel[0]) * (dt / 2);
    
    // printf("Initial y position is: %le\n", sptr[2].pos[1]);
    // printf("Initial vy velocity is: %le\n", sptr[2].vel[1]);
    // printf("Estimated vy veolcity is: %le\n", sptr[2].est_vel[1]);
    sptr[i].pos[1] += (sptr[i].vel[1] + sptr[i].est_vel[1]) * (dt / 2);
    
    printf("%le %le\n", sptr[i].pos[0], sptr[i].pos[1]);


    // printf("Initial vx velocity is: %le\n", sptr[2].vel[0]);
    // printf("Initial ax accleration is: %le\n", sptr[2].accel[0]);
    // printf("Estimated ax acceleration is: %le\n", sptr[2].est_accel[0]);
    sptr[i].vel[0] += (sptr[i].accel[0] + sptr[i].est_accel[0]) * (dt / 2);
    sptr[i].vel[1] += (sptr[i].accel[1] + sptr[i].est_accel[1]) * (dt / 2);

    // printf("The new planetary velocities are vx = %le and vy = %le\n", sptr[2].vel[0], sptr[2].vel[1]);
}

void output(Planet *sptr, int i) {
    FILE *result_ptr = NULL;
    result_ptr = fopen("results.txt", "w");

    double dt, T, freq, dump_time, time_until_dump; // 4e7

    printf("Please input a value for the time step and time period in days, separated by a space: ");
    scanf("%lg %lg", &dt, &T);


    printf("\nNow please select the frequency of the position outputs, in units of per days: ");
    scanf("%lg", &freq);

    dt = seconds(dt);
    T = seconds(T);
    dump_time = freq * dt;
    time_until_dump = dump_time;

    if(result_ptr != NULL) {
        // the for loop starts at time 0 and iterates until a given period
        // the time step is then increased by an amount dt and decreases to count on the data dump time by dt after each iteration
        for(double t = 0.0; t < T; t += dt, time_until_dump -= dt){
            printf("The current time is: %lg    time until dump: %lg\n", t, time_until_dump);
            double dist = distance(sptr, i);
            predict(sptr, dt, dist, i);
            correct(sptr, dt, i);
            if(time_until_dump <= 0.0) {
                time_until_dump = dump_time; // reseting the time until the next result output back to the original elapse time 
                fprintf(result_ptr, "%le %le\n", sptr[i].pos[0], sptr[i].pos[1]); // outputting position results to a text file once every 7 days
                printf("Dumping\n");
            }  
        }
    }
    else {
        printf("Unable to open results file.\n");
        exit(1);
    }
            
    fclose(result_ptr);
}