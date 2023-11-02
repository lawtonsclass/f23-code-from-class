#include <iostream>
#include "searching.h"
using namespace std;

int main() {
  vector<int> v = {8, 6, 7, 5, 3, 0, 9}; 
  cout << linearSearch(v, 3) << endl;
  cout << linearSearch(v, 42) << endl;

  cout << endl;

  vector<int> v2 = {1, 7, 33, 42, 55, 87}; 
  cout << binarySearch(v2, 33) << endl;
  cout << binarySearch(v2, 55) << endl;
  cout << binarySearch(v2, 12) << endl;
  cout << binarySearch(v2, 87) << endl;

  return 0;
}
