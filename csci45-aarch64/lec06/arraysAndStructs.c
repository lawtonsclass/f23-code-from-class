#include <stdio.h>

struct blah {
  int x;
  int y;
  int z;
};

int main() {
  int arr[] = {7, 8, 9};

  struct blah b; // = {7, 8, 9};
  b.x = 7;
  b.y = 8;
  b.z = 9;

  return 0;
}
