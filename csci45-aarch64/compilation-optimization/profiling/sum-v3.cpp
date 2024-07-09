#include <iostream>
using namespace std;

void fillArray(int* arr, int size) {
  // while size isn't a multiple of 4, fill it one at a time
  int i = 0;
  while (size > 0 && (size & 0b11) != 0) {
    *arr = i; 
    i++;
    arr++;
    size--;
  }

  // now we can work 4 at a time

  // start v0 full of {i, i+1, i+2, i+3}
  asm("dup v0.4S, %w0" :: "r"(i) : "v0"); // %w0 gets replaced with
                                          // whatever register i is in
                        // ^ we're reading from i (r for make sure
                        // it's in a register) and clobbering v0
  asm("mov w3, #0\n\t"
      "mov v1.4S[0], w3\n\t"
      "mov w3, #1\n\t"
      "mov v1.4S[1], w3\n\t"
      "mov w3, #2\n\t"
      "mov v1.4S[2], w3\n\t"
      "mov w3, #3\n\t"
      "mov v1.4S[3], w3\n\t"
      "add v0.4S, v0.4S, v1.4S" ::: "w3", "v0", "v1");
  // start v1 full of {4, 4, 4, 4}
  asm("movi v1.4S, #4" ::: "v1");

  while (size > 0) {
    // store v0 into arr
    asm("st1 {v0.4S}, [%0]" :: "r"(arr) : "v0"); // %0 gets replaced
                                                 // with whatever
                                                 // register arr is in
    // increment v0 using v1
    asm("add v0.4S, v0.4S, v1.4S" ::: "v0", "v1");
    // we just filled 4 elements
    arr += 4;
    size -= 4;
  }
}

long sumArray(int* arr, int size) {
  long res = 0;

  for (int i = 0; i < size; i++) {
    res += arr[i];
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
