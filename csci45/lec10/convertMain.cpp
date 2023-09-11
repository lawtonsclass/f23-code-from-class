#include <iostream>
using namespace std;

extern "C" void convert_to_all_caps(char* str);

int main() {
  char str[] = "hello, world!\n";

  convert_to_all_caps(str);

  cout << str;

  return 0;
}
