#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

// return x^n
double pow(double x, int n) {
  if (n < 0) {
    throw runtime_error("can't take a number to a negative power!!!");
  }

  if (n == 0) {
    return 1.0; // base case
  } else {
    // recursive case: x^n = x * x^(n-1)
    return x * pow(x, n-1);
  }
}

int flipBit(unsigned int x, int whichBit) {
  if (whichBit < 0 || whichBit > 31) {
    throw string("invalid bit!!!");
  }

  return x ^ (1 << whichBit);
}

int main() {
  try {
    cout << pow(2.5, 5) << endl;
    cout << pow(2.5, -5) << endl;
  } catch (runtime_error& e) {
    cout << e.what() << endl;
  }

  try {
    cout << flipBit(15, 1) << endl;
    cout << flipBit(15, -1) << endl;
    cout << flipBit(15, 2) << endl;
  } catch (string& s) {
    cout << s << endl;
  }

  return 0;
}
