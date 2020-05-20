#include <stdio.h>
#define MAX 50

typedef int KEYTYPE;

typedef struct {
    KEYTYPE key;
} REGISTER;

typedef struct {
    REGISTER A[MAX + 1]; // "A" with MAX elements
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

int searchSentryOrdened(LIST *l, KEYTYPE ch) {
    int i = 0;
    l->A[l->nroElem].key = ch; // Sentry

    while (l->A[i].key < ch) i++;

    if (i == l->nroElem || l->A[i].key != ch) return -1;
    else return i;
}


// Binary search
int searchKeyList(LIST* l, KEYTYPE ch) {
    int left, right, middle;
    left = 0;
    right = l->nroElem - 1;

    while (left <= right) {
        middle = ((left + right) / 2);
        if (l->A[middle].key == ch) {
        return middle;
        } else {
            if (l->A[middle].key < ch) left = middle + 1;
                else right = middle - 1;
        }
    }

    return -1;
}

int insertElemList(LIST* l, REGISTER reg, int i) {
    int j;

    if ((l->nroElem == MAX) || (i < 0) || (i > l->nroElem))
        return -1;

    for (j = l->nroElem; j > i; j--) l->A[j] = l->A[j-1]; // Move value of index j-1 to j (move values to right)

    l->A[i] = reg; // after moved the values, insert reg on index i
    l->nroElem++; // update the numbers of elements of list A
    return 0;
}

int deleteElemList(KEYTYPE ch, LIST* l) {
    int pos, j;
    pos = searchKeyList(l, ch);
    
    if (pos == -1) return -1;
    
    for (j = pos; j < l->nroElem-1; j++)
        l->A[j] = l->A[j+1];

    l->nroElem--;
    return 0;
}

int deleteElemListWithBinarySearch(LIST* l, KEYTYPE ch) {
    int pos, j;
    pos = binarySearch(l, ch);

    if (pos == -1) return -1;

    for (j = pos; j < l->nroElem -1; j++)
        l->A[j] = l->A[j+1];

    l->nroElem--;
    return 0;
}  

void restartList(LIST *l) {
    l->nroElem = 0;
}
