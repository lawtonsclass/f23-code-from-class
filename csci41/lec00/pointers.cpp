#include <iostream>
using namespace std;

void add1(int* p2) {
  *p2 = *p2 + 1;
}

int main() {
  int x = 42;
  int* p = &x;
  cout << x << endl;
  cout << *p << endl;

  add1(&x);
  cout << x << endl;

  return 0;
}
