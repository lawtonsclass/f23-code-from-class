#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Statistician {
  public:
    // operations
    void init();
    void addNumber(int n);
    int getMax();
    double average();
    int getCount();
    vector<int> getNums();

    // it's okay for this function to access my private member vars!
    friend void add1ToEveryNum(Statistician& s);

  private:
    // data
    int count;
    int currentMax;
    vector<int> nums;
};

void assertTrue(bool b, string description) {
  if (b) {
    cout << "PASSED: " << description << endl;
  } else {
    cout << "FAILED: " << description << endl;
  }
}

void Statistician::init() {
  count = 1;
  currentMax = 42;
  nums = {42};
}

void Statistician::addNumber(int n) {
  nums.push_back(n); 
  count++;
  if (count == 1) {
    currentMax = n; // the first number
  } else if (n > currentMax) {
    currentMax = n; // we just saw a bigger number;
  }
}

int Statistician::getMax() {
  return currentMax;
}

double Statistician::average() {
  double avg = 0.0;

  for (int n : nums) avg += n;

  avg = avg / count;

  return avg;
}

int Statistician::getCount() {
  return count;
}

vector<int> Statistician::getNums() {
  return nums;
}

void add1ToEveryNum(Statistician& s) {
  for (int i = 0; i < s.nums.size(); i++) {
    s.nums.at(i)++;
  }

  s.currentMax++;
}

void testMax() {
  // Make a new Statistician s
  Statistician s;
  // Call init() on it
  s.init();
  // getMax() should return 42 right now
  assertTrue(s.getMax() == 42, "getMax == 42");
  // Add 43 to s
  s.addNumber(43);
  // getMax() should return 43 now
  assertTrue(s.getMax() == 43, "getMax == 43");
  // Add 44 to s
  s.addNumber(44);
  // getMax() should return 44 now
  assertTrue(s.getMax() == 44, "getMax == 44");
  // Add 0 to s
  s.addNumber(0);
  // getMax() should still return 44
  assertTrue(s.getMax() == 44, "getMax == 44");
}

int main() {
  Statistician s;
  s.init();

  while (true) {
    cout << "Enter the next number (-1 to quit): ";
    int n;
    cin >> n;

    if (n == -1) {
      break;
    } else {
      s.addNumber(n);
    }
  }

  add1ToEveryNum(s);

  cout << s.getCount() << endl;
  cout << s.getMax() << endl;
  for (int num : s.getNums()) {
    cout << num << " ";
  }
  cout << endl;
  cout << s.average() << endl;

  testMax();

  return 0;
}
