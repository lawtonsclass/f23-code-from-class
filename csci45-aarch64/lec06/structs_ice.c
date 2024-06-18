#include <stdio.h>

struct blah {
  double x;
  int y;
};

int main() {
  int arr[] = {7, 8, 9};

  struct blah b; // = {7, 8, 9};
                 
  
  int offset = (void*)&b.y - (void*)&b.x;
  printf("%d\n", offset);

  return 0;
}
