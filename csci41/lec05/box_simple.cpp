#include <iostream>
using namespace std;

class Box {
  public:
    Box();
    int getVal() const;
    void setVal(int newVal);

    // destructor
    ~Box();
    // copy constructor
    Box(const Box& other);
    // copy assignment operator
    Box& operator=(const Box& other);

  private:
    int val;
};

Box::Box() : val(0) { }

int Box::getVal() const {
  return val;
}

void Box::setVal(int newVal) {
  val = newVal;
}

Box::~Box() {
  cout << "Box destructor called for Box with val = " << val << endl;
  // the default destructor is empty!
}

// copy constructs the member vars!
Box::Box(const Box& other) : val(other.val) {
  cout << "Box copy constructor called for Box with val = " << other.val << endl;
}

Box& Box::operator=(const Box& other) {
  cout << "Box copy assignment called for Box with val = " << other.val << endl;
  // copy assigns all the member vars! 
  val = other.val;

  // return a reference to ourselves
  // this is a Box* -- a pointer to ourselves
  return *this;
}

int main() {
  Box b;
  cout << b.getVal() << endl;
  b.setVal(42);
  cout << b.getVal() << endl;

  Box b2(b);
  b2.setVal(43);
  cout << b2.getVal() << endl;
  Box b3 = b2; // this is still the copy constructor, surprisingly!
  b3.setVal(44);
  cout << b3.getVal() << endl;

  Box b4;
  b4.setVal(45);
  b4 = b3;
  cout << b4.getVal() << endl;

  // destructors for all Boxes get called right before they get
  // reclaimed
  return 0;
}
