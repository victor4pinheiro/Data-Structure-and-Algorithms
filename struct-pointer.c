#include <stdio.h>

struct person
{
  int age;
  float weight;
};

int main()
{
  // "object" *personPtr is a pointer of person
  // person1 is a normal variable of person
  struct person *personPtr, person1;

  // the adress of person1 is stored in the personPtr
  personPtr = &person1;

  printf("Enter age: ");
  scanf("%d", &personPtr->age);

  printf("Enter weight: ");
  scanf("%f". &personPtr->weight);

  printf("Displayin:\n");
  // %d is a decimal integer (it is not recognizes octadecimal and hexadecimal)
  printf("Age: %d\n", personPtr->age);
  printf("weight: %f", personPtr->weight);

  return 0;

}
