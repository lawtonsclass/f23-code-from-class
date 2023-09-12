#include <iostream>
#include <string>
#include "adder.h"
using namespace std;

int main() {
  Adder<int> a; 
  a.x = 42;
  a.y = 43;
  cout << a.add() << endl;

  Adder<string> b; 
  b.x = "42";
  b.y = "43";
  cout << b.add() << endl;

  return 0;
}
