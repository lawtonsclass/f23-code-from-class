#include <iostream>
using namespace std;

int fact(int n) {
  if (n == 0) {
    // 0! = 1 (base case)
    return 1;
  } else {
    // n! = n * (n-1)! (recursive case)
    return n * fact(n-1);
  }
}

int main() {
  cout << fact(5) << endl;

  return 0;
}
