#include <iostream>
using namespace std;

void uhoh() {
  int x = 42;
  int* i = nullptr;
  cout << *i << endl;
}

int main() {
  uhoh();

  return 0;
}
