#include <iostream>
using namespace std;

int sumArray(int* arr, int size) {
  if (size == 0) return 0;
  else return arr[0] + sumArray(arr+1, size-1);
}

int main() {
  int arr[] = {1, 2, 3};
  cout << sumArray(arr, 3) << endl;

  return 0;
}
