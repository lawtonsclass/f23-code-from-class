#include <iostream>
#include <string>
using namespace std;

template <class T> // this line introduces a type variable
T maximum(T a, T b) {
  if (a > b) return a;
  else return b;
}

int main() {
  cout << maximum<int>(42, 43) << endl;
  cout << maximum(3.14, 2.71) << endl; // C++ can infer that we want maximum<double> here
  cout << maximum<string>("abc", "bcd") << endl;

  return 0;
}
