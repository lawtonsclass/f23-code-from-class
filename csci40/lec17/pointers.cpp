#include <iostream>
using namespace std;

int main() {
  int x = 5;
  int* p; // p is a ptr to an int--it can hold addrs of ints
  cout << p << endl;

  p = nullptr; // nullptr is a special, unused addr
  cout << p << endl;

  p = &x;
  cout << p << endl;

  cout << *p << endl;

  *p = *p + 1;
  cout << x << endl;
  cout << *p << endl;

  ////////////////////////////
  cout << endl;

  int* q = &x;
  int** r = &q;
  int*** z = &r;

  cout << x << endl;
  cout << *p << endl;
  cout << *q << endl;
  cout << **r << endl;
  cout << ***z << endl;
  


  return 0;
}
