#include <stdio.h>

struct user {
  char firstName[125], lastName[125], email[255];
  int age;
};

int main()
{
  struct user *pointerUser, anyUser;

  pointerUser = &anyUser;

  printf("What is you first name? ");
  scanf("%s", &pointerUser->firstName);

  printf("What is your last name? ");
  scanf("%s", &pointerUser->lastName);

  printf("What is your email? ");
  scanf("%s", &pointerUser->email);

  printf("How old are you? ");
  scanf("%d", &pointerUser->age);

  printf("\nDisplayin your inputs: \n");
  printf("First name: %s \n", pointerUser->firstName );
  printf("Last name: %s \n", pointerUser->lastName);
  printf("Email: %s \n", pointerUser->email);
  printf("Age: %d", pointerUser->age);

  return 0;
}
