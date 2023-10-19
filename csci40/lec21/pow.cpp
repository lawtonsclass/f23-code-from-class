#include <iostream>
using namespace std;

// returns m^n
double pow(double m, int n) {
  if (n == 0) {
    // base case: anything to the 0th power is 1
    return 1.0;
  } else {
    // recursive case: m^n = m * m^(n-1)
    return m * pow(m, n-1);
  }
}

int main() {
  cout << pow(2.5, 5) << endl;
  cout << pow(2, 4) << endl;
  cout << pow(2, 5) << endl;

  return 0;
}
