#include <iostream>
#include "recursion.h"
using namespace std;

int main() {
  cout << pow(2.0, 5) << endl;

  vector<int> v = {2, 4, 6, 8, 10};
  cout << binarySearch(v, 2, 0, v.size()-1) << endl;
  cout << binarySearch(v, 1, 0, v.size()-1) << endl;
  cout << binarySearch(v, 8, 0, v.size()-1) << endl;

  return 0;
}
