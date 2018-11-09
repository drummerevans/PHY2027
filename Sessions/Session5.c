#include <stdio.h>

typedef struct animal {
    char name[30];
    int age;
    char bark[30];
} Dog;

void barks(Dog *ptr);

int main() {
    Dog mydog = {0}; // creating a new variable 'mydog' of the structure-defined data type: Dog

    printf("Please, enter the values for the name, age and bark of the dog, separated by spaces: \n");
    scanf("%s %d %s", mydog.name, &mydog.age, mydog.bark); // inputting in dog details into the new structure variable 'mydog'

    barks(&mydog);

    printf("The structure \'my dog\' now contains name: %s, age: %d, bark: %s\n", mydog.name, mydog.age, mydog.bark);

    return 0;
}

void barks(Dog *ptr) {
    
    printf("The dog %s, with age %d, says %s\n", ptr->name, ptr->age, ptr->bark);
}