#include <iostream>
#include <string>
using namespace std;

void printChars(const string& s) {
  if (s == "") {
    // base case: there are no char to print
    // do nothing
  } else {
    // recursive case
    // print the first char
    cout << s.at(0) << endl;
    // recursively print the smaller string
    printChars(s.substr(1));
  }
}

void printCharsReverse(const string& s) {
  if (s == "") {
    // base case: there are no char to print
    // do nothing
  } else {
    // recursive case
    // recursively print the smaller string in reverse
    printCharsReverse(s.substr(1));
    // print the first char
    cout << s.at(0) << endl;
  }
}

int main() {
  string s = "blah";
  printChars(s);
  cout << endl;
  printCharsReverse(s);

  return 0;
}
