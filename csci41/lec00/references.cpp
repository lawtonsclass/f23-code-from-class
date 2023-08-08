#include <iostream>
#include <vector>
using namespace std;

int sum_vector(const vector<int>& v) {
  // v.at(0) = 42;
  int sum = 0;
  for (int x : v) {
    sum += x;
  }
  return sum;
}

int main() {
  int x = 42;
  int& y = x;
  x++;
  y++;
  cout << x << endl;
  cout << y << endl;

  vector<int> v = {1, 2, 3, 4, 5};
  cout << sum_vector(v) << endl;

  return 0;
}
