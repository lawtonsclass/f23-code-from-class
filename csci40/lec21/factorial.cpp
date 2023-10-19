#include <iostream>
using namespace std;

// returns n!
int fact(int n) {
  if (n == 1) {
    // base case: 1! = 1
    return 1;
  } else {
    // recursive case: n! = n * (n-1)!
    return n * fact(n-1);
  }
}

int fact_iterative(int n) {
  int product = 1;

  for (int i = n; i >= 1; i--) {
    product *= i;
  }

  return product;
}

int main() {
  cout << fact(5) << endl;
  cout << fact_iterative(5) << endl;

  return 0;
}
