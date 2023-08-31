#include <iostream>
using namespace std;

int fact(int n) {
  if (n == 0) {
    // base case
    return 1;
  } else {
    // recursive case
    return n * fact(n-1);
  }
}

int main() {
  cout << fact(5) << endl; 
  cout << fact(0) << endl; 
  cout << fact(2) << endl; 

  return 0;
}
