#include <iostream>
using namespace std;

int* foo() {
  int* i = new int;

  *i = 42;

  cout << *i << endl;

  return i;
}

int main() {
  int* x = foo();  // the address of foo's i

  (*x)++;

  cout << *x << endl;

  delete x;

  return 0;
}
