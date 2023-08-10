#include <iostream>
#include <string>
using namespace std;

int main() {
  string s = "Hello"; 

  cout << s << endl;
  cout << s.at(0) << endl;
  cout << s.at(1) << endl;

  s.at(0) = 'h';
  cout << s << endl;

  string s2;
  cout << "Enter a word: ";
  cin >> s2;
  cout << "s2: " << s2 << endl;

  return 0;
}
