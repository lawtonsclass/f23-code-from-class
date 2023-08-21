#include <iostream>
using namespace std;

int main() {
  int y = 0x1287; // let's use gdb to see this stored in little endian mode!
                  
  int x = 0b00010101;
  cout << x << endl;

  // extract bit 2: and with 4 (0b0100)
  if ((x & 4) != 0) {
    cout << "bit 2 was set!\n";
  }

  // set bit 5 (or with 0b100000 -- 32)
  x = x | 32;
  cout << x << endl;

  // negate using ~ and +
  x = (~x) + 1;
  cout << x << endl;

  // extract bits 2-5 from x
  // x & 0b00111100
  cout << (x & (0b1111 << 2)) << endl;

  // to extract just bit 2, you could and with 1 << 2

  return 0;
}
