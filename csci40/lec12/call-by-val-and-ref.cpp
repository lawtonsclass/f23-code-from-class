#include <iostream>
using namespace std;

void inc_by_val(int a) {
  a++;
}

void inc_by_ref(int& a) {
  a++;
}

int main() {
  int x = 42;

  inc_by_val(x);
  cout << x << endl;

  inc_by_ref(x);
  cout << x << endl;

  return 0;
}
