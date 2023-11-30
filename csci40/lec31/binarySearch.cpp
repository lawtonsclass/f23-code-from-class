#include <iostream>
#include <vector>
using namespace std;

int binarySearch(const vector<int>& v, int valToSearchFor) {
  // search space is initially the entire vector
  int lo = 0;
  int hi = v.size() - 1;

  while (lo <= hi) {
    int mid = (lo + hi) / 2;

    if (valToSearchFor < v.at(mid)) {
      // look to the left
      hi = mid - 1;
    } else if (valToSearchFor > v.at(mid)) {
      // look to the right
      lo = mid + 1;
    } else {
      // we found it!
      return mid;
    }
  }

  return -1; // we didn't find it :(
}

int main() {
  vector<int> v = {2, 4, 6, 8, 10};

  cout << binarySearch(v, 2) << endl;
  cout << binarySearch(v, 1) << endl;
  

  return 0;
}
