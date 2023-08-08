#include <iostream>
using namespace std;

int main() {
  int count = 0;
  int currentMax;

  while (true) {
    cout << "Enter the next number (-1 to quit): ";
    int n;
    cin >> n;

    if (n == -1) {
      break;
    }

    count++;
    if (count == 1) {
      currentMax = n; // the first number
    } else if (n > currentMax) {
      currentMax = n; // we just saw a bigger number;
    }
  }

  cout << count << endl;
  cout << currentMax << endl;

  return 0;
}
