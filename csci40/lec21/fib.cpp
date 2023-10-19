#include <iostream>
using namespace std;

// returns the nth fibonacci number
int fib(int n) {
  if (n == 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  } else {
    // recursive case
    return fib(n-1) + fib(n-2);
  }
}

int main() {
  cout << fib(7) << endl; 
  cout << fib(100) << endl; 

  return 0;
}
