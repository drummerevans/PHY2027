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

typedef struct student {
    char name[50];
    char surname[50];
    int age;
    float mark[5]; // an array containing marks of five different assignments
    float average_mark;
    char grade;
} Student;

void indata(Student *sptr);
void final_mark(Student *sptr);


int main() {
    Student *struc_ptr = NULL;
    struc_ptr = (Student *)malloc(NMAX * sizeof(Student)); // allocating 8 spaces for our structure array

    char identity[20] = "Matt";
    char again[20];
    

    printf("Input name: \n");
    scanf("%s", again);
    printf("\n%s was entered\n", again);

    if(strcmp(again, identity) == 0) {
        printf("String matching works!\n");
    }
    else {
        printf("Student not found.\n");
    }

    indata(struc_ptr);
    final_mark(struc_ptr);
    
    return 0;
}

// indata reads data 
void indata(Student *sptr) {

    FILE *fptr;
    fptr = fopen("scores.txt", "r");

    if(fptr != NULL) {
        // the loop reads one line at a time from the text file "scores.txt"
        for(int i = 0; !feof(fptr); i++) {
            fscanf(fptr, "%s %s %d", sptr[i].name, sptr[i].surname, &sptr[i].age);

            // the nested loop reads elements in from the text file into the 'mark' array in the structure
            for(int j = 0; j < 5; j++) {
                fscanf(fptr, "%f ", &sptr[i].mark[j]);
            }

            fprintf(stdout, "%s %s %d\n", sptr[i].name, sptr[i].surname, sptr[i].age);
            fprintf(stdout, "%f %f %f %f %f\n", sptr[i].mark[0], sptr[i].mark[1], sptr[i].mark[2], sptr[i].mark[3], sptr[i].mark[4]);
        }
        
        free(sptr);
        fclose(fptr);

        }

        // exits the program if the text file if there is a problem
        else {
            printf("Unable to open text file\n");
            exit(1); 
        }
    }

void final_mark(Student *sptr) {
    float sum, average;
    for(int i = 0; i < NMAX; i++) {
        printf("Student %d marks are: \n", i);
        for(int j = 0; j < 5; j++) {
            printf("The student mark is: %f\n", sptr[i].mark[j]);
            sum += sptr[i].mark[j];
        }
        average = sum / 5.0;
        sptr[i].average_mark = average;
        printf("The average of student %d is %f\n", i, sptr[i].average_mark);

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
    printf("Student %d grade is %c\n", i, sptr[i].grade);
    sum = 0;
    average = 0;
    }
}