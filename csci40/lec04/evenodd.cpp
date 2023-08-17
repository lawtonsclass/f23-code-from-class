#include <iostream>
using namespace std;

int main() {
  int n;

  cout << "Enter a number: ";
  cin >> n;

  if (n % 2 == 0) {
    // even
    cout << "even!\n";
  } else {
    // odd
    cout << "odd!\n";
  }

  return 0;
}
