#include <iostream>
#include <string>
using namespace std;

// int doub(int x) { return x + x; }

template <class U>
U doub(U x) { return x + x; }

template <class T>
class Doubler {
  public:
    T x;
    T doub() const;
};

template <class T>
T Doubler<T>::doub() const {
  return x + x;
}


int main() {
  cout << doub(42) << endl;
  cout << doub<double>(3.14) << endl;
  cout << doub(string("Hello, world!")) << endl;

  Doubler<int> d;
  d.x = 42;
  cout << d.doub() << endl;

  Doubler<double> d2;
  d2.x = 3.14;
  cout << d2.doub() << endl;

  return 0;
}
