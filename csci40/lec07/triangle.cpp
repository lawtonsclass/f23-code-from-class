#include <iostream>
using namespace std;

int main() {
  // execute the body 4 times
  for (int i = 0; i < 4; i++) {
    // print i+1 stars and a newline
    for (int j = 0; j < i+1; j++) {
      cout << '*';
    }
    cout << '\n';
  }

  return 0;
}
