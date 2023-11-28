#include <iostream>
#include <vector>
using namespace std;

void swap_by_value(int x, int y) {
  int temp = x;
  x = y;
  y = temp;
}

void swap_by_reference(int& x, int& y) {
  int temp = x;
  x = y;
  y = temp;
}

int sum(const vector<int>& v) {
  int res = 0;

  for (int i : v) {
    res += i;
  }

  return res;
}

int main() {
  int a = 42;
  int b = 43;

  swap_by_value(a, b);
  cout << a << " " << b << endl;

  swap_by_reference(a, b);
  cout << a << " " << b << endl;

  vector<int> v(1000, 42); // v is a vector holding 1000 elems, all set to 42
  cout << sum(v) << endl;

  return 0;
}
