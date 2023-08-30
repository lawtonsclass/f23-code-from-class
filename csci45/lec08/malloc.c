#include <stdio.h>
#include <stdlib.h> // where malloc and free live

int main() {
  int* arr = malloc(3 * sizeof(int)); // makes an arry of 3 ints on
                                      // the heap

  arr[0] = 1;
  arr[1] = 2;
  arr[2] = 3;

  printf("%d\n", arr[0] + arr[1] + arr[2]);

  free(arr);

  return 0;
}
