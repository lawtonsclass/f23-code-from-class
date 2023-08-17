#include <iostream>
#include "counter.h"
using namespace std;

int main() {
  Counter c; // implicitly calling the default constructor for us!
  c.inc();
  c.inc();
  c.inc();
  cout << c.getCount() << endl;
  c.reset(42);
  c.inc();
  cout << c.getCount() << endl;

  Counter c2(42); // calls the parameterized constructor
  c2.inc();
  c2.inc();
  c2.inc();
  c2.inc();
  cout << c2.getCount() << endl;

  Counter* cPointer = &c;
  cout << (*cPointer).getCount() << endl;
  cout << cPointer->getCount() << endl;


  // when you say c + c2, the compiler tries to call operator+(c, c2)
  // OR c.operator+(c2)
  Counter c3 = c + c2; // secretly translated into c.operator+(c2)
  cout << c3.getCount() << endl;

  Counter c4 = c * c2; // call operator*(c, c2)
  cout << c4.getCount() << endl;

  cout << c4 << endl; // operator<<(cout, c4)
  cout << c3 << endl;

  return 0;
}
