#include <iostream>
#include <string>
using namespace std;

// any time somebody inherits from CanPrint, we know that they have a
// print method that they implemented themselves!
class CanPrint {
  public:
    // this is a pure virtual method--it marks CanPrint as an
    // *abstract class*
    virtual void print() = 0;
};

class IntPrinter : public CanPrint {
  public:
    int i;
    void print() override { cout << i << endl; }
};

class StringPrinter : public CanPrint {
  public:
    string s;
    void print() override { cout << s << endl; }
};

int main() {
  // can't do the following:
  // CanPrint c;
  
  IntPrinter ip;
  ip.i = 42;
  ip.print();

  StringPrinter sp;
  sp.s = "Hi mom!";
  sp.print();

  return 0;
}
