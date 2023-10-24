#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

void capitalize(char* str) {
  if (strlen(str) == 0) {
    // base case: do nothing
  } else {
    // recursive case
    str[0] = toupper(str[0]);
    capitalize(str + 1);
  }
}

int main() {
  char s[] = "blah";
  capitalize(s);
  cout << s << endl;

  return 0;
}
