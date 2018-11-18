/*
Assessment 3 for PHY2027
Date 19/11/2018
*/

/*
This program is a database containing various information about several students.
The user input the name of the student to obtain the mark and grade for that particular student.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NMAX 8
#define CMAX 50

// declaring a strucutre data type capable of storing all the relevant details for a number of students
typedef struct student {
    char name[50];
    char surname[50];
    int age;
    float mark[5]; // an array containing marks of five different assignments
    float average_mark; // a value containg the final mark of the student
    char grade;
} Student;

void indata(Student *sptr);
void final_mark(Student *sptr);
void retrieve(Student *sptr, char array[CMAX]);


int main() {
    Student *struc_ptr = NULL; // declaring and initializing a structure pointer
    struc_ptr = (Student *)malloc(NMAX * sizeof(Student)); // allocating 8 spaces for our structure array of students
    char name_input[CMAX];
    char option;
    int decision;

    indata(struc_ptr);
    final_mark(struc_ptr);
    
    // the loop will extract as many marks and grades for any student as requested by the user
    do {
        printf("Please enter a student you would to find their mark and grade for:\n");
        scanf("%s", name_input);
        retrieve(struc_ptr, name_input);
        
        printf("\nWould you like to find the mark and grade for another student? Y or N\n");
        printf("\t1. Yes\n");
        printf("\t2. No\n");
        printf("Please enter 1 or 2: \n");
        scanf("%d", &decision);
    }
    while(decision == 1);

    free(struc_ptr);
    
    return 0;
}

// the indata function reads data from the text file
void indata(Student *sptr) {
    FILE *fptr;
    fptr = fopen("scores.txt", "r"); // opening the 'scores.txt' text file for reading

    if(fptr != NULL) {
        // the loop reads one line at a time from the text file "scores.txt"
        for(int i = 0; !feof(fptr); i++) {
            fscanf(fptr, "%s %s %d", sptr[i].name, sptr[i].surname, &sptr[i].age);
            // the nested loop reads elements in from the text file into the 'mark' array in the structure
            for(int j = 0; j < 5; j++) {
                fscanf(fptr, "%f ", &sptr[i].mark[j]);
            }
        }
        fclose(fptr); // closing the text file after the data has been scanned into the relevant structures
        }
        // exits the program if there is a problem with opening the specified text file
        else {
            printf("Unable to open text file\n");
            exit(1); 
        }
    }

// this function will calculate and return an average mark and grade
// these will be stored in each structure under the 'average_mark' and 'grade' members
void final_mark(Student *sptr) {
    float sum, average;
    for(int i = 0; i < NMAX; i++) {
        for(int j = 0; j < 5; j++) {
            sum += sptr[i].mark[j];
        }
        average = sum / 5.0;
        sptr[i].average_mark = average;

    // the conditional statements assign a relevant grade to the strucutre member 'grade'
    // this is based on the average mark of the student
    if(sptr[i].average_mark >= 70.0) {
        sptr[i].grade = 'A';
    }
    else if(sptr[i].average_mark >= 60.0) {
        sptr[i].grade = 'B';
    }
    else if(sptr[i].average_mark >= 50.0) {
        sptr[i].grade = 'C';
    }
    else if(sptr[i].average_mark >= 40.0) {
        sptr[i].grade = 'D';
    }
    else if(sptr[i].average_mark >= 30.0) {
        sptr[i].grade = 'E';
    }
    else {
        sptr[i].grade = 'F';
    }
    sum = 0;
    average = 0;
    }
}

// this function retrives the average mark and grade for a given student, specfied by the user in main
void retrieve(Student *sptr, char array[CMAX]) {
    printf("Name entered was: %s\n", array);
    for(int i = 0; i < NMAX; i++) {
        if(strcmp(array, sptr[i].name) == 0) {
            printf("The final mark for %s is %f and the grade is %c\n", sptr[i].name, sptr[i].average_mark, sptr[i].grade);
        }
    } 
}