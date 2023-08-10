#include <iostream>
#include <string>
using namespace std;

int main() {
  cout << "Enter a lowercase word: "; 
  string word;
  cin >> word;

  // change word.at(0)
  int dist = 'a' - 'A'; // offset amount
  word.at(0) = word.at(0) - dist;

  cout << word << endl;

  return 0;
}
