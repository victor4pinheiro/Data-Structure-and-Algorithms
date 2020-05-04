#include <stdio.h>
#define maxHeight 225 // Just any value

typedef struct {
  int weight; // Weight (kg)
  int height; // Height (cm)
} WeightHeight;

int main() {
  // ..

  WeightHeight person1;
  person1.weight = 80;
  person1.height = 185;

  printf("Weight: %i.\n Height: %i.\n ", person1.weight, person1.height);

  if (person1.height > maxHeight) printf("Above average height.\n");
  else printf("Below average height.\n");

  return 0; // if program work well, return 0
}
