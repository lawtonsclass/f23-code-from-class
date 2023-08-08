#include <iostream>
using namespace std;

int foo(const int y) {
  return y+1;
}

int main() {
  const int x = 42;
  cout << x * 2 << endl;

  // x can't change!
  // x++;

  int z = 55;
  cout << foo(z) << endl;

  return 0;
}
