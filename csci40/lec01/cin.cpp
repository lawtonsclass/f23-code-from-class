#include <iostream>
using namespace std;

int main() {
  int x; // x holds "nothing" right now--I'll fill it with whatever the user types

  cout << "Enter an int: ";
  cin >> x;
  cout << "You typed " << x << endl;

  char c;
  cout << "Enter a char: ";
  cin >> c;

  double d;
  cout << "Enter a double: ";
  cin >> d;

  cout << c << endl;
  cout << d << endl;

  return 0;
}
