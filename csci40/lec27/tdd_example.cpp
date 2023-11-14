#include <iostream>
#include <string>
using namespace std;

void setThirdBit(int& x);
bool isThirdBitSet(int x);

void assertTrue(bool b, string description) {
  if (b) {
    cout << "PASSED: " << description << endl;
  } else {
    cout << "FAILED: " << description << endl;
  }
}

void testSetThirdBit() {
  int x = 11;
  setThirdBit(x);
  assertTrue(x == 11, "setThirdBit(11)");

  x = 3;
  setThirdBit(x);
  assertTrue(x == 11, "setThirdBit(3)");
}

void testIsThirdBitSet() {
  // assertTrue(isThirdBitSet(11) == true, "isThirdBitSet(11)");
  // assertTrue(isThirdBitSet(3) == false, "isThirdBitSet(3)");

  // these are equivalent to the above
  assertTrue(isThirdBitSet(11), "isThirdBitSet(11)");
  assertTrue(!isThirdBitSet(3), "isThirdBitSet(3)");
}

int main() {
  testSetThirdBit();
  testIsThirdBitSet();

  return 0;
}

void setThirdBit(int& x) {
  x = x | (1 << 3); 
}

bool isThirdBitSet(int x) {
  return (x & (1 << 3)) != 0;
}
