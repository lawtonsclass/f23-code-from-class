#include <iostream>
using namespace std;

int main() {
  int* heap_arr = new int[42];

  heap_arr[12] = 42;

  cout << heap_arr[12] << endl;

  delete[] heap_arr;

  return 0;
}
