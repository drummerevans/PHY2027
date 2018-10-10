#include <stdio.h>

int add(void);

int main() {
    
    printf("The addition function produces... %d", add());

    return 0;
}

int add(void) {
    return 5 + 5;
}