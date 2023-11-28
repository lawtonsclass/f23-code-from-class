#include <iostream>
#include <vector>
using namespace std;

int main() {
  int x = 42;
  int* y = &x; // y points to x
  int** z = &y;

  cout << x << endl;
  cout << y << endl;
  cout << *y << endl;
  cout << z << endl;
  cout << *z << endl;
  cout << **z << endl;

  vector<int> v = {1, 2, 3};
  vector<int>* vp = &v;
  cout << (*vp).size() << endl;
  cout << vp->size() << endl;

  return 0;
}
