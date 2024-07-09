#include <iostream>
using namespace std;

void fillArray(int* arr, int size) {
  for (int i = 0; i < size; i++) {
    arr[i] = i;
  }
}

long sumArray(int* arr, int size) {
  long res = 0;

  int idx = 0;
  for (int i = 0; i < size; i++) {
    res += arr[idx];
    idx = (idx + 50021) % size; // so many cache misses :'(
  }

  return res;
}

int main() {
  int size = 100'000'007;
  int* arr = new int[size];

  fillArray(arr, size);
  long sum = sumArray(arr, size);

  cout << "sum: " << sum << endl;

  return 0;
}
