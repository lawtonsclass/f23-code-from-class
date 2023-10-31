#include <iostream>
#include <stdexcept>
using namespace std;

int divide(int dividend, int divisor) {
  if (divisor == 0) {
    throw runtime_error("division by 0!!!");
  }

  return dividend / divisor;
}

int main() {
  int n1 = 42, n2; 

  while (true) {
    try {
      cout << "Enter a divisor: ";
      cin >> n2;
      cout << divide(n1, n2) << endl;
      break;
    } catch (runtime_error& e) {
      // handle the error by asking for a new divisor!
      cout << "Can't divide by 0! Try again.\n";
    }
  }

  return 0;
}
