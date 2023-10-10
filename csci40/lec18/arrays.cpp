#include <iostream>
using namespace std;

int main() {
  int arr[] = {5, 6, 7};
  cout << arr << endl;
  cout << &arr[0] << endl; // arr is &arr[0]
  cout << arr[0] << endl;
  cout << *arr << endl;    // *arr is arr[0]

  cout << arr[1] << endl;
  cout << *(arr + 1) << endl; // equivalent to arr[1]

  int* p = arr;
  cout << p[2] << endl; // *(p + 2)

  int* q = new int[42]; // q holds the addr of the first elem in this
                        // size-42 arr that we just made on the heap

  q[5] = 55;
  cout << q[5] << endl;

  delete[] q; // remember the []s for an arr on the heap

  return 0;
}
