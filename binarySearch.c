#include <stdio.h>

int binarySearch(int arr[], int left, int right, int x)
{
  if (right >= left) {
    int middle = left + (right - left);
    

    // If the element is present at the middle
    // itself 
    if (arr[middle] == x)
      return middle;

    // If element is smaller than mid, then
    // it can only be present in left subarray 
    if (arr[middle] > x)
      return binarySearch(arr, left, middle - 1, x);

    // Else the element can only be present
    // in right subarray 
    return binarySearch(arr, middle + 1, right, x);

  }
  
  return -1;

}

int main(void)
{
  int arr[] = { 2, 3, 4, 10, 40};
  int n = sizeof(arr) / sizeof(arr[0]);

  int x = 10;

  int result = binarySearch(arr, 0, n - 1, x);

  (result == -1) ? printf("Element is not present in array")
                 : printf("Element is present at index %d", result);

  return 0;
}

