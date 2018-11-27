#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct planet{
    char name[20];
    float mass;
    float distance;
    float speed;
} Planet;

void read(Planet *sptr);


int main() {
    Planet *struc_ptr = NULL; // declaring and initializing a structure pointer
    struc_ptr = (Planet *)malloc(9 * sizeof(Planet)); // allocating 9 spaces for our structure array of planets

    read(struc_ptr);

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
            fscanf(fptr, "%s %e %f %f", sptr[i].name, &sptr[i].mass, &sptr[i].distance, &sptr[i].speed);
            fprintf(stdout, "Name: %s, Mass: %ekg, Distance: %ekm, speed: %fkm/s\n", sptr[i].name, sptr[i].mass, sptr[i].distance, sptr[i].speed);
        }
        fclose(fptr); // closing the text file after the data has been scanned into the relevant structures
        }
        // exits the program if there is a problem with opening the specified text file
        else {
            printf("Unable to open text file\n");
            exit(1); 
        }
    }