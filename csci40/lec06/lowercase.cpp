#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
  cout << "Enter a word: ";
  string s;
  cin >> s;

  // iterate through every valid index of s, replacing each char with
  // its lowercase equivalent
  /*
  int i = 0;
  while (i < s.size()) {
    s.at(i) = tolower(s.at(i));
    i++;
  }
  */

  for (int i = 0; i < s.size(); i++) {
    s.at(i) = tolower(s.at(i));
  }

  cout << s << endl;
  

  return 0;
}
