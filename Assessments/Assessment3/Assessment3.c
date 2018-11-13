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

typedef struct student {
    char name[100];
    int age;
    float mark[5]; // an array containing marks of five different assignments
    char date[20];
} Student;

int indata();

int main() {
    indata();
    
    return 0;
}

int indata() {
    FILE *fptr;
    char text[300];

    fptr = fopen("student_info.txt", "r");

    if(fptr != NULL) {
        // the while loop reads one line at a time from the text file "student_info.txt"
        while(fgets(text, 300, fptr)) { 
            printf("%s", text);
            }
        printf("\n%s", text);
        fclose(fptr);
        return 0;
        }

        else {
            printf("Unable to open text file\n");
            return 1;
        }
    }
