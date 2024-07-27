// compile with: g++ -g -fsanitize=undefined ubsan.cpp -o ubsan
#include <iostream>
#include <climits>
using namespace std;

int main() {
  int arr1[42];
  int arr2[55];
  int arr3[88];

  // out of bounds on the stack (the compiler is able to figure out
  // this is undefined behavior, and can optimize it however it wants)
  arr2[58] = 0xabad1dea;

  int x = 42;
  // shifting more bits than exist in an int
  int y = x >> 35;

  int z = INT_MAX;
  // signed overflow
  z++;

  int* p = nullptr;
  // null dereference
  cout << *p << endl;

  return 0;
}
