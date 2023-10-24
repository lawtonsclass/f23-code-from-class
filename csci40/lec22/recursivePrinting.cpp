#include <iostream>
using namespace std;

void printFrom1To(int n) {
  if (n == 0) {
    // base case: do nothing
  } else {
    // recursive case
    // recursively print from 1 to n-1
    printFrom1To(n-1);
    // print n
    cout << n << endl;
  }
}

void reversePrintFrom1To(int n) {
  if (n == 0) {
    // base case: do nothing
  } else {
    // recursive case
    // print n
    cout << n << endl;
    // recursively print from n-1 to 1
    reversePrintFrom1To(n-1);
  }
}

int main() {
  printFrom1To(5);
  cout << endl;
  reversePrintFrom1To(5);

  return 0;
}
