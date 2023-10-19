#include <iostream>
using namespace std;

// issue 1: forgets the base case
int fact1(int n) {
  cout << "inside fact1(" << n << ")" << endl;
  return n * fact1(n-1);
}

int fact2(int n) {
  cout << "inside fact2(" << n << ")" << endl;
  if (n == 1) {
    // base case: 1! = 1
    return 1;
  } else {
    // incorrect recursive case
    return fact2(n);
  }
}

int main() {
  // cout << fact1(5) << endl;
  cout << fact2(5) << endl;

  return 0;
}
