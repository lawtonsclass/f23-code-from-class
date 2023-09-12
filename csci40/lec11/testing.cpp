#include <iostream>
#include <string>
using namespace std;

int factorial(int n) {
  if (n < 0) {
    return -1;
  }

  int product = 1;

  for (int i = n; i >= 1; i--) {
    product = product * i;
  }

  return product;
}

void assertTrue(bool b, string description) {
  if (b) {
    cout << "PASSED: " << description << endl;
  } else {
    cout << "FAILED: " << description << endl;
  }
}

int main() {
  /*
  if (factorial(3) == 6) {
    cout << "PASSED: factorial(3)" << endl;
  } else {
    cout << "FAILED: factorial(3)" << endl;
  }

  if (factorial(4) == 24) {
    cout << "PASSED: factorial(4)" << endl;
  } else {
    cout << "FAILED: factorial(4)" << endl;
  }
  */

  assertTrue(factorial(3) == 6, "factorial(3)");
  assertTrue(factorial(4) == 24, "factorial(4)");
  assertTrue(factorial(5) == 120, "factorial(5)");
  assertTrue(factorial(0) == 1, "factorial(0)"); // loop body runs 0 times
  assertTrue(factorial(1) == 1, "factorial(1)"); // loop body runs 1 time
  assertTrue(factorial(-1) == -1, "factorial(-1)");

  return 0;
}
