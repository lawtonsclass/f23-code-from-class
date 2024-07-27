// compile with g++ -g -fsanitize=address asan.cpp -o asan
#include <iostream>
using namespace std;

int main() {
  int* arr = new int[42];

  // buffer overflow
  // arr[43] = 0xabad1dea;
  
  delete[] arr;
  // double free
  // delete[] arr;

  // memory leak
  // int* x = new int;

  return 0;
}
