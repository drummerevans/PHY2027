#include <stdio.h>
#include <string.h>

int main() {
    char *names[3] = {0};

    // for(int i = 0; i < 3; i++) {
    //     printf("Element[%d] contains %s\n", i, names[i]);
    // }

    char last_name[10] = "Last_One";
    names[0] = "BigB";
    names[1] = "Trundles";
    names[2] = last_name;

    printf("Now names reads: \n");
    for(int i = 0; i < 3; i++) {
        printf("Element[%d] contains %s\n", i, names[i]);
    }

    return 0;
}