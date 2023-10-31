#include <iostream>
#include <stdexcept>
using namespace std;

// returns n!
int fact(int n) {
  if (n < 1) {
    throw runtime_error("Can't calculate the factorial of numbers < 1 :(");
  }

  if (n == 1) {
    // base case: 1! = 1
    return 1;
  } else {
    // recursive case: n! = n * (n-1)!
    return n * fact(n-1);
  }
}

int main() {
  try {
    cout << fact(5) << endl;
    cout << fact(-1) << endl;
  } catch (runtime_error& e) {
    cout << e.what() << endl;
  }

  return 0;
}
