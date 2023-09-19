#include "sumOfSquares.h"

int add(int x, int y) {
  // give back (i.e., return) the sum of x and y
  return x + y;
}

int square(int x) {
  return x*x;
}

int sumOfSquaresFrom1To(int n) {
  int sum = 0;

  for (int i = 1; i <= n; i++) {
    sum = add(sum, square(i));
  }

  return sum;
}
