#include <iostream>
#include <vector>
using namespace std;

class Counter {
  public:
    Counter(); // *default* constructor
    Counter(int startingCount); // parameterized constructor
    void inc();
    void reset(int newCount = 0);
    int getCount() const;
    Counter operator+(const Counter& other);
    friend Counter operator*(const Counter& a, const Counter& b);

  private:
    int count;
    vector<int> blah; // default constructor call automatically unless you change it
    const double d;
};

Counter::Counter() : count(0), d(3.14) {
  // because I initialized everything in the initializer list, the
  // body of the constructor can be empty!

  // because I don't mention the vector here, it gets default
  // constructed
}

Counter::Counter(int startingCount) : count(startingCount), blah(100, 42), d(5.67) { }

void Counter::inc() {
  count++;
}

void Counter::reset(int newCount) {
  count = newCount;
}

int Counter::getCount() const {
  return count;
}

Counter Counter::operator+(const Counter& other) {
  // called when we're supposed to add our count with other.count

  Counter res;

  res.count = count + other.count;

  return res;
}

Counter operator*(const Counter& a, const Counter& b) {
  // option 1:
  Counter res;
  res.count = a.count * b.count;
  return res;

  // option 2:
  // Counter res(a.getCount() * b.getCount());
  // return res;
}

ostream& operator<<(ostream& os, const Counter& c) {
  // print to os however you want
  os << "Count: " << c.getCount();

  // remember to always return os at the end
  return os;
}

int main() {
  Counter c; // implicitly calling the default constructor for us!
  c.inc();
  c.inc();
  c.inc();
  cout << c.getCount() << endl;
  c.reset(42);
  c.inc();
  cout << c.getCount() << endl;

  Counter c2(42); // calls the parameterized constructor
  c2.inc();
  c2.inc();
  cout << c2.getCount() << endl;

  Counter* cPointer = &c;
  cout << (*cPointer).getCount() << endl;
  cout << cPointer->getCount() << endl;


  // when you say c + c2, the compiler tries to call operator+(c, c2)
  // OR c.operator+(c2)
  Counter c3 = c + c2; // secretly translated into c.operator+(c2)
  cout << c3.getCount() << endl;

  Counter c4 = c * c2; // call operator*(c, c2)
  cout << c4.getCount() << endl;

  cout << c4 << endl; // operator<<(cout, c4)
  cout << c3 << endl;

  return 0;
}
