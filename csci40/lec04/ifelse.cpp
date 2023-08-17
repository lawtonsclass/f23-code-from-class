#include <iostream>
#include <string>
using namespace std;

int main() {
  string today;

  cout << "Enter what day it is: ";
  cin >> today;

  if (today == "Wednesday") {
    cout << "Wear pink!\n";
  } else {
    cout << "Don't wear pink!\n";
  }

  // more straight-line code can go here...

  cout << "done\n";

  return 0;
}
