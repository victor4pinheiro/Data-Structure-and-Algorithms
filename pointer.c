#include <stdio.h>

int main(){
  int x = 25; // Variable x initialized with value 25
  int* y = &x; // Variable y receives variable x's adress
  *y = 30; // x receives value 30 because y is pointer to x

  printf("Current value of x: %i\n", x);
  return 0;
}
