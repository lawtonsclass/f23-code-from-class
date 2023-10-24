#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> perms(const string& s) {
  if (s == "") {
    // base case
    vector<string> result = {""};
    return result;
  } else {
    // recursive case
    vector<string> result;

    // try every char and scramble the remaining characters
    for (int i = 0; i < s.size(); i++) {
      char startingChar = s.at(i);
      string remainingCharacters = s;
      remainingCharacters.erase(i, 1); // removes the startingChar
      vector<string> smallerStringPerms = perms(remainingCharacters);
      for (const string& smallerStringPerm : smallerStringPerms) {
        // add startingChar to the front and put it in the result vector
        result.push_back(startingChar + smallerStringPerm);
      }
    }

    return result;
  }
}

int main() {
  vector<string> v = perms("abc"); 

  for (const string& s : v) {
    cout << s << endl;
  }

  return 0;
}
