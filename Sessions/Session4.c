#include <stdio.h>

#define NMAX 11
#define LENGTH 5
#define I 3
#define J 3

void hello_func(char msg[NMAX]);
void add_arrs(int arr1[LENGTH], int arr2[LENGTH], int arr3[LENGTH]);
void matrix_add(int mat1[I][J], int mat2[I][J], int mat3[I][J]);

int main() {
    char greeting[NMAX]={'A','A','A','A','A','A','A','A','A','A','A'};

    int iarray1[LENGTH] = {1, 2, 3, 4, 5}; 
    int iarray2[LENGTH] = {2, 4, 6, 8, 10};
    int iarray3[LENGTH] = {0};

    int matrix1[I][J] = {{  1,
                            2,
                            3}, {1, 2, 3}, {1, 2, 3}};

    int matrix2[I][J] = {{1, 2, 3}, 
                         {1, 2, 3},
                         {1, 2, 3}};

    int matrix3[I][J] = {{0}, {0}};

    for(int i = 0; i < LENGTH; i++) {
        printf("%d\n", iarray3[i]);
    }

    printf("The character array now reads:\n ");
    for(int i = 0; i < sizeof(greeting); i++) {
        printf("%c\n", greeting[i]);
    }

    printf("Input the messages \'HelloWorld\': ");
    printf("%d\n", (int) sizeof(greeting));

    scanf("%s", greeting);
    // for(i = 0; i < 11; i++) {
    //     scanf("%c\n", &greeting[i]);
    // }

    printf("%d\n", (int) sizeof(greeting));

    printf("The character array now reads:\n ");
    for(int i = 0; i < sizeof(greeting); i++) {
        printf("%c\n", greeting[i]);
    }

    printf("My function reads: ");
    hello_func(greeting);
    add_arrs(iarray1, iarray2, iarray3);

    printf("\nPassing arrays by reference gives: \n");
    for(int i; i < LENGTH; i++) {
        printf("%d\n", iarray3[i]);
    }

    printf("\nThe matrix addition of the two matrices gives: \n");
    matrix_add(matrix1, matrix2, matrix3);

    return 0;
}

void hello_func(char msg[NMAX]) {
    printf("%s\n", msg);
}

void add_arrs(int arr1[LENGTH], int arr2[LENGTH], int arr3[LENGTH]) {
    for(int i = 0; i < LENGTH; i++) {
        arr3[i] = arr1[i] + arr2[i];
        printf("Array1 + Array2 = %d\n", arr3[i]);
    }
}

void matrix_add(int mat1[I][J], int mat2[I][J], int mat3[I][J]) {
    for(int i = 0; i < I; i++) {
        for(int j = 0; j < J; j++) {
            mat3[i][j] = mat1[i][j] + mat2[i][j];
            printf("%d\t", mat3[i][j]);
        }
    printf("\n");
    }
}