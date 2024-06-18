#include <iostream>
using namespace std;

extern "C" int fact(int n);
extern "C" int fib(int n);

int main() {
  cout << fact(5) << endl;
  cout << fib(6) << endl;

  return 0;
}
