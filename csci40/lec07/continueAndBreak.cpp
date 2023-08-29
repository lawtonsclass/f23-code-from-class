#include <iostream>
using namespace std;

int main() {
  for (int i = 1; i <= 10; i++) {
    if (i == 3) {
      continue; // skips the rest of the loop and goes to the next iteration
    }

    cout << i << endl;
  }

  while (true) {
    cout << "Enter a char (q to quit): ";
    char c;
    cin >> c;

    if (c == 'q') {
      break; // stop the loop
    }

    cout << "You typed: " << c << endl;
  }

  return 0;
}
