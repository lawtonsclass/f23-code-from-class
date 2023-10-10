#include <iostream>
using namespace std;

void uh_oh() {
  int x = 42;
  int* p = nullptr;
  cout << *p << endl;
}

int main() {
  uh_oh();

  return 0;
}
