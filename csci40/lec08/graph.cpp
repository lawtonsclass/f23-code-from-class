#include <iostream>
#include <cmath>
using namespace std;

int main() {
  for (int y = 12; y >= -11; y--) {
    for (int x = -38; x <= 39; x++) {
      if (y == round(sqrt(10*10 - x*x))) {
        // top half of the circle! 
        cout << "*";
      } else if (y == round(-sqrt(10*10 - x*x))) {
        // bottom half of the circle! 
        cout << "*";
      } else if (x == 0 && y == 0) {
        // axes meeting
        cout << "+";
      } else {
        // empty space
        cout << " ";
      }
    }
    cout << endl;
  }

  return 0;
}
