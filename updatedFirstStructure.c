#include <stdio.h>
#include <malloc.h>
#define maxHeight 225;

typedef struct {
  int weight; // weight (kg)
  int height; // height (cm)
} WeightHeight;

int main() {
  WeightHeight* person1 = (WeightHeight*) malloc(sizeof(WeightHeight));
  person1->weight = 80;
  person1->height = 185;

  printf("weight: %i, height: %i ", person1->weight, person1->height);
  return 0;
}
