#include <iostream>
using namespace std;

int main() {
  int a, b;
  cout << "Enter two numbers: ";
  cin >> a >> b;

  while (b != 0) {
    int old_b = b;
    b = a % b;
    a = old_b;
  }

  cout << a << endl;

  return 0;
}
