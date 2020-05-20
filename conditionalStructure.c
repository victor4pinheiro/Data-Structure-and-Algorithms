#include <stdio.h>

typedef struct {
    int age;
} AgeMajority;

int main() {

    AgeMajority ageConditionally;
    
    printf("How old are you?");
    scanf("%i", &ageConditionally.age);

    if (ageConditionally.age < 3 ) {
        printf("Baby");
    } else if (ageConditionally.age < 14) {
        printf("Child");
    } else if (ageConditionally.age < 18) {
        printf("Teenager");
    } else if (ageConditionally.age < 65) {
        printf("Adult");
    } else {
        printf("Elderly");
    }
    return 0;
        
}

