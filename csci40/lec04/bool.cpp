#include <iostream>
using namespace std;

int main() {
  bool b1 = 42 < 43;
  bool b2 = 45 >= 55;
  bool b3 = true;
  bool b4 = false;

  cout << b1 << endl;
  cout << b2 << endl;

  if (b1) {
    cout << "b1 was true\n";
  }

  if (b2) {
    cout << "b2 was true\n";
  } else {
    cout << "b2 was false\n";
  }

  cout << (true && true) << endl; // only this one is true
  cout << (true && false) << endl;
  cout << (false && true) << endl;
  cout << (false && false) << endl;

  return 0;
}
