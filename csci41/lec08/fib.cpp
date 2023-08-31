#include <iostream>
using namespace std;

int fib(int n) {
  if (n == 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  } else {
    // recursive case
    return fib(n-2) + fib(n-1);
  }
}

int fibIterative(int n) {
  int a = 0, b = 1;
  for (int i = 0; i < n; i++) {
    int oldB = b;
    b = a + b;
    a = oldB;
  }
  return a;
}

int main() {
  cout << fib(5) << endl;
  cout << fib(0) << endl;
  cout << fib(2) << endl;

  // cout << fib(200) << endl;
  cout << fibIterative(200) << endl;

  return 0;
}
