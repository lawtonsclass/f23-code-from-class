#include <iostream>
#include <stdexcept>
using namespace std;

int fact(int n) {
  if (n < 0) {
    throw runtime_error("negative factorials don't exist");
  }

  if (n == 0) {
    // base case
    return 1;
  } else {
    // recursive case
    return n * fact(n-1);
  }
}

void assertTrue(bool b, string description) {
  if (b) {
    cout << "PASSED: " << description << endl;
  } else {
    cout << "FAILED: " << description << endl;
  }
}

void testFact() {
  assertTrue(fact(5) == 120, "5!");
  assertTrue(fact(2) == 2, "2!");
  assertTrue(fact(1) == 1, "1!");
  assertTrue(fact(0) == 1, "0!");
}

int main() {
  testFact();

  return 0;
}
