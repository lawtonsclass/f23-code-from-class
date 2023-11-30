#include <iostream>
using namespace std;

int multiplyBy2ToTheN(int x, int n) {
  return x << n;
}

int flipBit(unsigned int x, int whichBit) {
  return x ^ (1 << whichBit);
}

int main() {
  // 3 * (2^4)
  cout << multiplyBy2ToTheN(3, 4) << endl;  

  cout << flipBit(13, 1) << endl;
  cout << flipBit(15, 1) << endl;

  return 0;
}
