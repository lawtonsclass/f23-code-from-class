#include <iostream>
using namespace std;

class Box {
  public:
    Box(int val1 = 0, int val2 = 0);
    int getVal1() const;
    int getVal2() const;
    void setVal1(int newVal);
    void setVal2(int newVal);

    // destructor
    ~Box();
    // copy constructor
    Box(const Box& other);
    // copy assignment operator
    Box& operator=(const Box& other);

  private:
    int* val1; // point to an int on the heap
    int* val2; // point to another int on the heap
};

Box::Box(int val1, int val2) : val1(new int(val1)), val2(new int(val2)) {
  // this->val1 = new int(val1);
  // this->val2 = new int(val2);
}

int Box::getVal1() const {
  return *val1;
}

int Box::getVal2() const {
  return *val2;
}

void Box::setVal1(int newVal) {
  *val1 = newVal;
}

void Box::setVal2(int newVal) {
  *val2 = newVal;
}

Box::~Box() {
  // the default destructor is empty!

  // we need to delete both vals
  delete val1;
  delete val2;
}

// copy constructs the member vars!
Box::Box(const Box& other) {
  val1 = new int(*other.val1); // new box on the heap for this val!
  val2 = new int(*other.val2); // new box on the heap for this val!
}

Box& Box::operator=(const Box& other) {
  // self-assignment check--don't let us copy ourselves into ourselves
  if (this == &other) {
    return *this; // do nothing
  }

  // copy assigns all the member vars! 
  delete val1;
  delete val2;
  val1 = new int(*other.val1); // new box on the heap for this val!
  val2 = new int(*other.val2); // new box on the heap for this val!

  // return a reference to ourselves
  // this is a Box* -- a pointer to ourselves
  return *this;
}

int main() {
  Box b1;
  b1.setVal1(42);
  b1.setVal2(43);
  Box b2(b1);
  b2.setVal1(44);
  b2.setVal2(45);
  Box b3;
  b3 = b2;
  b3 = b3;
  b3.setVal1(46);
  b3.setVal2(47);
  cout << b1.getVal1() << " " << b2.getVal1() << " " << b3.getVal1() << endl;
  cout << b1.getVal2() << " " << b2.getVal2() << " " << b3.getVal2() << endl;


  // destructors for all Boxes get called right before they get
  // reclaimed
  return 0;
}
