#include "recursion.h"
using namespace std;

// return x^n
double pow(double x, int n) {
  if (n == 0) {
    return 1.0; // base case
  } else {
    // recursive case: x^n = x * x^(n-1)
    return x * pow(x, n-1);
  }
}

int binarySearch(const vector<int>& v, int valToSearchFor, int lo, int hi) {
  if (lo > hi) {
    // base case: search space is empty
    return -1;
  }

  // recursive case: non-empty search space
  int mid = (lo + hi) / 2;

  if (valToSearchFor < v.at(mid)) {
    // look to the left
    return binarySearch(v, valToSearchFor, lo, mid - 1);
  } else if (valToSearchFor > v.at(mid)) {
    // look to the right
    return binarySearch(v, valToSearchFor, mid + 1, hi);
  } else {
    // we found it!
    return mid;
  }
}

