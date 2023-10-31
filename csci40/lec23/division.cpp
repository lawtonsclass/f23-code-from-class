#include <iostream>
using namespace std;

int divide(int dividend, int divisor) {
  if (divisor == 0) {
    cout << "Bad divisor!!!\n";
    return -1;
  }

  return dividend / divisor;
}

int main() {
  int n1 = 42, n2; 
  cout << "Enter a divisor: ";
  cin >> n2;
  cout << divide(n1, n2) << endl;

  return 0;
}
