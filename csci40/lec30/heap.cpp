#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int* i = new int; // i points to an int on the heap
  *i = 42;
  cout << *i << endl;
  delete i;

  cout << "Enter the size of the array: ";
  int size;
  cin >> size;

  int* arr = new int[size];

  for (int i = 0; i < size; i++) {
    cout << "Enter the next element: ";
    int nextElem;
    cin >> nextElem;
    arr[i] = nextElem;
  }

  double median; // median must be a double
  // sort the array first
  sort(arr, arr + size);
  if (size % 2 == 1) {
    // odd size: middle index is size / 2
    int mid = size / 2;
    median = arr[mid];
  } else {
    // even size: middle indices are (size / 2) and (size / 2) - 1
    int midRight = size / 2;
    int midLeft = size / 2 - 1;
    median = (arr[midLeft] + arr[midRight]) / 2.0;
  }

  // after we calculate the median, we are done with arr
  delete[] arr;

  cout << median << endl;

  return 0;
}
