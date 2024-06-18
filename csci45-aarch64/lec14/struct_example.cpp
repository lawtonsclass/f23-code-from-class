#include <iostream>
using namespace std;

struct blah {
  int x;
  char c1;
  char c2;
  int y;
};

int main() {
  cout << sizeof(blah) << endl;

  blah b;
  cout << &b << endl;
  cout << &(b.x) << endl;
  cout << (void*)&(b.c1) << endl;
  cout << (void*)&(b.c2) << endl;
  cout << &(b.y) << endl;

  return 0;
}
