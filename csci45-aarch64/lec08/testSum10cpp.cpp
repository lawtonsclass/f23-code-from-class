#include <iostream>
using namespace std;

extern "C" int sum10(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j);

int main() {
  cout << sum10(1, 2, 3, 4, 5, 6, 7, 8, 9, 10) << endl; 

  return 0;
}
