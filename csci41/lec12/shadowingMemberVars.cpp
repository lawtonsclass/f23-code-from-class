#include <iostream>
using namespace std;

class C {
  public:
    int getX();
    void setX(int newX);

  private:
    int x;
};

int C::getX() {
  return x;
}

void C::setX(int newX) {
  int x = newX;
  // ^ this creates a new *local* var called x that *shadows* the
  // x member var
  // correct way to do it: x = newX;
}

int main() {
  C c;
  c.setX(42); // ?!?
  cout << c.getX() << endl;

  return 0;
}
