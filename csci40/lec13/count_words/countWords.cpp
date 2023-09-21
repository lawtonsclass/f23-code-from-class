#include "countWords.h"
#include <cctype>
using namespace std;

int countWords(const string& s) {
  string state = "OUTSIDE";
  int count = 0;

  // run the state machine on every char in s
  for (int i = 0; i < s.size(); i++) {
    char currentChar = s.at(i);

    if (state == "OUTSIDE") {
      if (isspace(currentChar)) {
        state = "OUTSIDE";
      } else { // non-space
        state = "INSIDE"; 
        count++;
      }
    } else { // state == "INSIDE"
      if (isspace(currentChar)) {
        state = "OUTSIDE";
      } else { // non-space
        state = "INSIDE"; 
      }
    }
  }

  return count;
}
