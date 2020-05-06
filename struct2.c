#include <stdio.h>

struct StudentData {
  char *stu_name;
  int stu_id;
  int stu_age;
};

int main()
{
  struct StudentData student;

  student.stu_name = "Steve";
  student.stu_id = 0xFF;
  student.stu_age = 27;

  printf("Student name is: %s ", student.stu_name);
  printf("Student id is: %i ", student.stu_id);
  printf("Student age is: %i ", student.stu_age);

  return 0;
} 
