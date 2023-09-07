#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

int main() {
  char s[] = {'h', 'e', 'l', 'l', 'o', '\0'}; // a C-string
  char s2[] = "hello"; // shorthand for the above
  cout << s2 << endl;

  char s3[] = "42";
  cout << atoi(s3)*2 << endl;

  char s4[50] = "hi ";
  char s5[] = "mom!";
  strcat(s4, s5); // s4 = s4 + s5;
  cout << s4 << endl;

  cout << strlen(s2) << endl; // doesn't count '\0'

  cout << strcmp("abc", "bcd") << endl;
  cout << strcmp("bcd", "abc") << endl;
  cout << strcmp("abc", "abc") << endl;
  cout << strcmp("hello", "hi mom") << endl;

  return 0;
}
