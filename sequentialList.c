#include <stdio.h>
#define MAX 50

typedef int KEYTYPE;

typedef struct {
  KEYTYPE key;
  // other camps
} REGISTER;

typedef struct {
  REGISTER A[MAX]; // "A" with MAX elements
  int nroElem;
} LIST;

// The params contain LIST* l to store the adresses of the variables
// and modify the values of the original list
void initializeList(LIST* l) {
  l->nroElem = 0; // List initialized with value 0
}

int lenght(LIST* l) {
  return l->nroElem; // return the number of elements
}

void showList(LIST* l) {
  int i;
  printf("List: \" ");

  for (i = 0; i < l->nroElem; i++)
    printf("%i", l->A[i].key);
  printf("\"\n");
}

int searchKeyList(LISTA* l, KEYTYPE ch) {
  int i = 0;
  while (i < l->nroElem) {
    if(ch == l->A[i].key) return i;
    else i++;
  }
  return -1;
}

bool insertElemList(LIST* l, REGISTER reg, int i) {
  int j;

  if ((l->nrElem == MAX) || (i < 0) || (i > l->nroElem))
    return false;

  for (j = l->nrElem; j > i; j--) l->A[j] = l->A[j-1]; // Move value of index j-1 to j (move values to right)

  l->A[i] = reg; // after moved the values, insert reg on index i
  l->nroElem++; // update the numbers of elements of list A
  return true;
}

bool deleteElemList(KEYTYPE ch, LIST* l) {
  int pos, j;
  pos = searchKeyList(l, ch);
  if (pos == -1) return false;
  
  for (j = pos; j < l->nroElem-1; j++)
    l->A[j] = l->A[j+1];

  l->nroElem--;
  return true;
}

void restartList(LIST *l) {
  l->nroElem = 0;
}
