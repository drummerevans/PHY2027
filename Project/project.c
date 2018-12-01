#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define SUN_MASS 1988500e24
#define G 6.67e-11

typedef struct planet{
    char name[20];
    float mass;
    float position[2];
    float velocity[2];
} Planet;

void read(Planet *sptr);
float force(Planet *sptr);


int main() {
    float f;
    Planet *struc_ptr = NULL; // declaring and initializing a structure pointer
    struc_ptr = (Planet *)malloc(9 * sizeof(Planet)); // allocating 9 spaces for our structure array of planets

    read(struc_ptr);

    float x = struc_ptr[0].position;
    float y = 0;
    float theta = atan2(y, x);
    float vx = 0, vy = 0;
    float ax = 0, ay = 0;

    f = (G * SUN_MASS * struc_ptr[0].mass) / (pow(x, 2) + pow(y, 2));
    printf("%e", f);

    ax = f / struc_ptr[[0];
    

    free(struc_ptr);

    return 0;
}

// the read function reads data from the text file
void read(Planet *sptr) {
    FILE *fptr;
    fptr = fopen("data.txt", "r"); // opening the 'scores.txt' text file for reading

    if(fptr != NULL) {
        // the loop reads one line at a time from the text file "scores.txt"
        for(int i = 0; !feof(fptr); i++) {
            fscanf(fptr, "%s %e %f %f", sptr[i].name, &sptr[i].mass, &sptr[i].position, &sptr[i].velocity);
            fprintf(stdout, "Name: %s, Mass: %ekg, Distance: %em, speed: %fm/s\n", sptr[i].name, sptr[i].mass, sptr[i].position, sptr[i].velocity);
        }
        fclose(fptr); // closing the text file after the data has been scanned into the relevant structures
        }
        // exits the program if there is a problem with opening the specified text file
        else {
            printf("Unable to open text file\n");
            exit(1); 
        }
    }

// float force(Planet *sptr) {
//     float F;
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