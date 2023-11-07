#include "searching.h"
using namespace std;

int linearSearch(const vector<int>& v, int valToSearchFor) {
  // go through every index from left to right, looking for
  // valToSearchFor
  
  for (int i = 0; i < v.size(); i++) {
    if (v.at(i) == valToSearchFor) {
      // found it! return the index where it was
      return i;
    }
  }

  // if we got here, we didn't find it :(
  return -1;
}

int binarySearch(const vector<int>& v, int valToSearchFor) {
  // initially, the search space is the whole vector v
  int lo = 0;
  int hi = v.size() - 1;

  // keep searching as long as lo <= hi
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    int mid_val = v.at(mid);

    if (valToSearchFor < mid_val) {
      // the value I'm looking for is smaller--I need to look to the
      // left
      hi = mid - 1;
    } else if (valToSearchFor > mid_val) {
      // the value I'm looking for is bigger--I need to look to the
      // right
      lo = mid + 1;
    } else {
      // we found what we were looking for! It was at index mid
      return mid;
    }
  }

  // if we get here, lo passed hi--that means we didn't find it!
  return -1;
}
