#include <stdio.h>
#define MAXUSERS 200

typedef int IDTYPE;

typedef struct {
  IDTYPE value;
  char name[255];
  char email[255];
  int age;
} USERDATA;

typedef struct {
  USERDATA USER[MAXUSERS];
  int lengthElement;
} LISTUSER;

void initializeDatabase(LISTUSER* user) {
  user->lengthElement = 0;
}

int lenghtListUsers(LISTUSER* user) {
  return user->lengthElement;
}

void showListUser(LISTUSER* user){
  int count;
  printf("Start: ");

  for (count = 0; count< user->lengthElement; count++) {
    printf("%i", user->USER[count].value);
  }

  printf("\n End");

}

int searchUser(LISTUSER* user, IDTYPE id){
  int countSearch;

  while (countSearch < user->lengthElement) {
    if (id == user->USER[countSearch].value) {
      return countSearch;
    } else {
      countSearch++;
    }
  }

  return -1;
}

int insertUser(LISTUSER* user, USERDATA registerUser, int countCondition) {
  int countValueList;

  if ((user->lengthElement == MAXUSERS) || (countCondition < 0) || (countCondition > user->lengthElement)) {
    return 0;
  }

  for (countValueList = user->lengthElement; countValueList > countCondition; countValueList--) {
    user->USER[countValueList] = user->USER[countValueList - 1];
  }

  user->USER[countCondition] = registerUser;
  user->lengthElement++;
  return 1;
}

int deleteUser(LISTUSER* user, IDTYPE deleteId) {
  int position, count;
  position = searchUser(user, deleteId);

  if (position == -1) {
    return 1;
  }

  for (count = position; count < user->lengthElement - 1; count ++) {
    user->USER[count] = user->USER[count++];
  }

  user->lengthElement--;
  return 1;
}

void restartListUser (LISTUSER* user) {
  user->lengthElement = 0;
}

