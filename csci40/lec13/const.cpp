#include <iostream>
#include <vector>
using namespace std;

int sum_vector(const vector<int>& v) {
  // v.at(0) = 42; // we'd like this to not be possible

  int sum = 0;

  for (int elem : v) {
    sum += elem;
  }

  return sum;
}

int main() {
  int x = 42;
  const int y = x;
  x++;
  // y++;

  vector<int> v = {1, 2, 3, 4, 5};
  cout << sum_vector(v) << endl;
  cout << v.at(0) << endl;

  return 0;
}
