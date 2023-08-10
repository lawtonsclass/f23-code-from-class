#include <iostream>
#include <string>
using namespace std;

int main() {
  cout << "Enter a line: ";
  string line;
  getline(cin, line); // gets an entire line from the user (including whitespace)
  cout << "You typed: " << line << endl;

  return 0;
}
