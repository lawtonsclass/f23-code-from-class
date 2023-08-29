#include <iostream>
using namespace std;

int main() {
  // execute the body 4 times
  for (int i = 0; i < 4; i++) {
    // print 4 stars and a newline
    for (int j = 0; j < 4; j++) {
      cout << '*';
    }
    cout << '\n';
  }

  cout << endl;

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      // check to see if we're in the middle
      if (i >= 1 && i <= 2 && j >= 1 && j <= 2) {
        cout << ' ';
      } else {
        cout << '*';
      }
    }
    cout << '\n';
  }

  return 0;
}
