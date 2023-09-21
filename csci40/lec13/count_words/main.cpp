#include <iostream>
#include "countWords.h"
using namespace std;

void assertTrue(bool b, string description) {
  if (b) {
    cout << "PASSED: " << description << endl;
  } else {
    cout << "FAILED: " << description << endl;
  }
}

void testCountWords() {
  string s = "Hello, world!   blah\n\t    42";
  assertTrue(countWords(s) == 4, "count words in a 4-word sentence");
  assertTrue(countWords("   ") == 0, "count words in a 0-word sentence");
}

int main() {
  // string line;
  // cout << "Enter a line of text: ";
  // getline(cin, line);

  // cout << countWords(line) << endl;

  testCountWords();

  return 0;
}
