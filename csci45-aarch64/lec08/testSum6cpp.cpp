#include <iostream>
using namespace std;

extern "C" int sum6(int a, int b, int c, int d, int e, int f);

int main() {
  cout << sum6(1, 2, 3, 4, 5, 6) << endl; 

  return 0;
}
