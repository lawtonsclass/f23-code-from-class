#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Holder {
  public:
    Holder(int x) : x(x) {}
    int getX() const { return x; }

  private:
    int x;
};

bool operator<(const Holder& a, const Holder& b) {
  return a.getX() < b.getX();
}

bool holderCompare(const Holder& a, const Holder& b) {
  return a.getX() > b.getX();
}

class HolderComparisonClass {
  public:
    bool operator()(const Holder& a, const Holder& b) {
      return a.getX() < b.getX();
    }
};

int main() {
  Holder h1(42);
  Holder h2(55);
  Holder h3(128);

  vector<Holder> v = {h2, h3, h1};

  // option 1: make an operator<
  // sort(v.begin(), v.end());
  
  // option 2: make a comparison function
  // sort(v.begin(), v.end(), holderCompare);

  // option 3: comparison class
  HolderComparisonClass hc;
  cout << hc(h1, h2) << endl;
  sort(v.begin(), v.end(), hc);

  // secret option 4?: anonymous function
  // sort(v.begin(), v.end(), [](const Holder& a, const Holder& b){ return a.getX() < b.getX(); });

  for (const Holder& h : v) {
    cout << h.getX() << " ";
  }
  cout << endl;
  
  return 0;
}
