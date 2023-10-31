#include <iostream>
#include <vector>
using namespace std;

// merge the two sorted sub-arrays [start, mid] and [mid+1, end]
void merge(vector<int>& v, int start, int mid, int end) {
  // start on the left of each sorted sub-array
  int i = start;
  int j = mid + 1;

  // make temp array
  vector<int> temp(end - start + 1);

  int nextIndexInTempArray = 0;
  while (i <= mid && j <= end) {
    // pick the smaller thing: v.at(i) & v.at(j)
    if (v.at(i) < v.at(j)) {
      temp.at(nextIndexInTempArray) = v.at(i);
      i++;
    } else {
      temp.at(nextIndexInTempArray) = v.at(j);
      j++;
    }
    // get ready to fill in the next index of the temp array
    nextIndexInTempArray++;
  }

  // once the loop stops, we've run out of one of the sub-arrays--take
  // the rest of the other one
  if (i > mid) {
    // take the rest of the js
    while (j <= end) {
      temp.at(nextIndexInTempArray) = v.at(j);
      j++;
      nextIndexInTempArray++;
    }
  } else {
    // take the rest of the is
    while (i <= mid) {
      temp.at(nextIndexInTempArray) = v.at(i);
      i++;
      nextIndexInTempArray++;
    }
  }

  // copy the temp array back into the original vector v
  int idx = 0;
  for (int i = start; i <= end; i++) {
    v.at(i) = temp.at(idx);
    idx++;
  }
}

void mergesort(vector<int>& v, int start, int end) {
  // base case: the array is size <= 1, so it's already sorted
  if (end - start <= 0) return;
  // recursive case: sort each half of the array

  int mid = (start + end) / 2;
  // recursively sort the smaller arrays
  mergesort(v, start, mid);
  mergesort(v, mid + 1, end);
  // build up the bigger sorted array
  merge(v, start, mid, end);
}

int main() {
  vector<int> v = {8, 6, 7, 5, 3, 0, 9};

  mergesort(v, 0, v.size() - 1);

  for (auto x : v) {
    cout << x << " ";
  }
  cout << endl;

  return 0;
}
