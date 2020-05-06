#include <stdio.h>

struct numbers {
  int num1, num2;
};

int main()
{
  struct numbers s1 = {.num2 = 22, .num1 = 0xd3};
  struct numbers s2 = {.num2 = 0x35};

  printf("num1: %i, num2: %i \n", s1.num1, s1.num2);
  printf("num2: %i", s2.num2);

  return 0;
}
