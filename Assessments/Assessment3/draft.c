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
    char name[50];
    char surname[50];
    int age;
    float mark[5]; // an array containing marks of five different assignments
    char date[20];
} Student;

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
    Student *sptr = NULL;
    FILE *fptr;
    sptr = (Student *)malloc(8 * sizeof(Student)); // allocated space for our structure array

    fptr = fopen("scores.txt", "r");

    if(fptr != NULL) {
        // the while loop reads one line at a time from the text file "student_info.txt"
        for(int i = 0; !feof(fptr); i++) {
            fscanf(fptr, "%s %s %d", sptr[i].name, sptr[i].surname, &sptr[i].age);
            fscanf(fptr, "%f %f %f %f %f", &sptr[i].mark[0], &sptr[i].mark[1], &sptr[i].mark[2], &sptr[i].mark[3], &sptr[i].mark[4]);
            // fscanf(fptr, "%s", sptr[i].date);

            fprintf(stdout, "%s %s %d\n", sptr[i].name, sptr[i].surname, sptr[i].age);
            fprintf(stdout, "%f %f %f %f %f\n", sptr[i].mark[0], sptr[i].mark[1], sptr[i].mark[2], sptr[i].mark[3], sptr[i].mark[4]);
            // fprintf(stdout, "%s\n", sptr[i].date);
        }
        
        // printf("Values stored in \'names\' array are: \n");
        // for(int i = 0; i < 3; i++) {
        //     printf("Name %d is %s\n", i, names[i]);
        // }

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
        free(sptr);
        fclose(fptr);
        return 0;
        }

        else {
            printf("Unable to open text file\n");
            return 1;
        }
    }