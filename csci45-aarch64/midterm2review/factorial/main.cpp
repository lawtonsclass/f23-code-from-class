#include <iostream>
using namespace std;

extern "C" int factorial(int n);

int main() {
  cout << factorial(5) << endl;
  cout << factorial(0) << endl;
  cout << factorial(1) << endl;
  cout << factorial(3) << endl;

  return 0;
}
