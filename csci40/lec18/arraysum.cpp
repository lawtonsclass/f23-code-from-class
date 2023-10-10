#include <iostream>
using namespace std;

int main() {
  int n;
  cout << "Enter the array size: ";
  cin >> n;

  // make an array of n ints on the heap
  int* arr = new int[n];

  // fill it
  for (int i = 0; i < n; i++) {
    int nextElem;
    cout << "Enter the next element: ";
    cin >> nextElem;
    arr[i] = nextElem;
  }

  // sum everything
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
  }

  // done with arr; delete[] it!
  delete[] arr;

  cout << sum << endl;

  // now I could ask the user for another array, and reuse the first
  // array's memory!

  return 0;
}
