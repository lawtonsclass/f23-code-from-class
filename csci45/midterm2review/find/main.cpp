#include <iostream>
using namespace std;

extern "C" int find(const char* s, char c);

int main() {
  cout << find("Hello, world!", 'c') << endl;
  cout << find("Hello, world!", 'l') << endl;
  cout << find("Hello, world!", '!') << endl;

  return 0;
}
