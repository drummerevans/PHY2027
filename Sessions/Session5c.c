#include <stdio.h>
#include <stdlib.h>

typedef struct dog {
    char name[30];
    int age;
    char bark[30];
    struct dog *prev_dog;
    struct dog *next_dog;
} Dog;

void barks(Dog *ptr);

int main() {
    Dog *dog_a = NULL; 
    dog_a = (Dog *)malloc(sizeof(Dog)); // allocated space for our structure 
    dog_a->next_dog = (Dog *)malloc(sizeof(Dog)); // allocated space for our structure;
    dog_a->prev_dog = NULL;
    dog_a->age = 20;

    // dog_a->next_dog->age = 3;
    // dog_a->next_dog->age = 3;
    // dog_a->next_dog->next_dog = (Dog *)malloc(sizeof(Dog));
    // dog_a->next_dog->next_dog->age = 5;
    // dog_a->next_dog->next_dog->next_dog = NULL;

    int num_dogs = 4;
    Dog* pdog = dog_a;
    for(int i = 1; i < num_dogs; i++) {
        pdog->next_dog = malloc(sizeof(Dog));
        pdog = pdog->next_dog;
       
        pdog->age = i;
        pdog->next_dog = NULL;
    }

    for (Dog* ptr = dog_a; ptr != NULL; ptr = ptr->next_dog)
    {
        barks(ptr);
    }

    // for(int i = 0; i < 3; i++) {
    //     printf("Please, enter the values for the name, age and bark of the dog, press enter after each entry: \n");
    //     pdog = next_dog;
    //     // scanf("%s", pdog[i].name);
    //     // scanf("%d", &pdog[i].age);
    //     // scanf("%s", pdog[i].bark);
    //     // printf("%d\n",i);
    //     // scanf("%s %d %s", pdog[i].name, pdog[i].age, pdog[i].bark); // inputting in dog details into the new structure variable 'mydog'
    // }
    
    


    // printf("The structure \'my dog\' now contains name: %s, age: %d, bark: %s\n", mydog.name, mydog.age, mydog.bark);
    free(dog_a);

    return 0;
}

// int *p = &a;

void barks(Dog *ptr) {
    printf("The dog %s, with age %d, says %s\n", ptr->name, ptr->age, ptr->bark); 
    
    
}