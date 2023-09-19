#include <iostream>
using namespace std;

int main() {
  int x = 42;
  int& z = x; // z is a reference to x

  cout << x << endl;
  cout << z << endl;

  x++;
  cout << x << endl;
  cout << z << endl;

  z++;
  cout << x << endl;
  cout << z << endl;

  return 0;
}
