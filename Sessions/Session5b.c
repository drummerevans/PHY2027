#include <stdio.h>
#include <stdlib.h>

typedef struct dog {
    char name[30];
    int age;
    char bark[30];
    // Dog *prev_dog;
    // Dog *next_dog;
} Dog;

void barks(Dog *ptr);

int main() {
    Dog *pdog = NULL; // declaring and initializing the structure pointer to NULL
    pdog = (Dog *)malloc(3 * sizeof(Dog)); // allocated space for our structure 

    for(int i = 0; i < 3; i++) {
        printf("Please, enter the values for the name, age and bark of the dog, press enter after each entry: \n");
        scanf("%s", pdog[i].name);
        scanf("%d", &pdog[i].age);
        scanf("%s", pdog[i].bark);
        // scanf("%s %d %s", pdog[i].name, pdog[i].age, pdog[i].bark); // inputting in dog details into the new structure variable 'mydog'
    }
    
    barks(pdog);

    // printf("The structure \'my dog\' now contains name: %s, age: %d, bark: %s\n", mydog.name, mydog.age, mydog.bark);
    free(pdog);

    return 0;
}

// int *p = &a;

void barks(Dog *ptr) {
    for(int i = 0; i < 3; i++) {
        // accessing the values of the elements stored in the array of structures, shown below
        printf("The dog %s, with age %d, says %s\n", ptr[i].name, ptr[i].age, ptr[i].bark); 
    }

    // comment
    
}