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

// typedef struct student {
//     char name[100];
//     int age;
//     float mark[5]; // an array containing marks of five different assignments
//     char date[20];
// } Student;

int indata();

int main() {
    char identity[20] = "Trundles";
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

    indata();
    
    return 0;
}

int indata() {
    FILE *fptr;
    char text[25];
    int age[25] = {0};
    float marks[25] = {0};
    char date[25];

    char *names[3];

    int arr_size = sizeof(age) / sizeof(int);
    printf("Array size: %d\n", arr_size);

    fptr = fopen("pupilmarkdata.txt", "r");

    if(fptr != NULL) {
        // the while loop reads one line at a time from the text file "student_info.txt"
        for(int i = 0; !feof(fptr); i++) {
            fscanf(fptr, "%s %d %f %s", text, &age[i], &marks[i], date);
            if(i == 0) {
                printf("what is it %s?\n", text);
                names[0] = text;
                printf("%s\n", names[0]);
            }
            if(i == 5) {
                printf("what is it %s?\n", text);
                printf("%s\n", names[0]);
                names[1] = text;
                printf("%s\n", names[0]);
            }
            // if(i == 10) {
            //     names[2] = text;
            // }
            fprintf(stdout, "%s %d %f %s\n", text, age[i], marks[i], date);
        }
        
        // printf("Values stored in \'names\' array are: \n");
        // for(int i = 0; i < 3; i++) {
        //     printf("Name %d is %s\n", i, names[i]);
        // }

        printf("The age and the marks are as follows: \n");
        printf("%s\n", names[0]);

        float sum[20];

        // for(int i = 0; i < arr_size; i++) {
        //     if(i < 5) {
        //         if(i == 0) {
        //             //
        //         }
        //     }

        //     fprintf(stdout, "%d %f\n", age[i], marks[i]);
        // }


        
     
        // for(int i = 0; i < 5; i++) {
        //     printf("Marks: %f\n", marks[i]);
        // }

        // fclose(fptr);
        // return 0;
        }

        else {
            printf("Unable to open text file\n");
            return 1;
        }
    }