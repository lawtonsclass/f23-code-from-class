#include <iostream>
#include <vector>
using namespace std;

struct Stats {
  int count;
  int currentMax;
  vector<int> nums;
};

int main() {
  Stats s;
  s.count = 0;

  while (true) {
    cout << "Enter the next number (-1 to quit): ";
    int n;
    cin >> n;

    if (n == -1) {
      break;
    } else {
      s.nums.push_back(n);
    }

    s.count++;
    if (s.count == 1) {
      s.currentMax = n; // the first number
    } else if (n > s.currentMax) {
      s.currentMax = n; // we just saw a bigger number;
    }
  }

  cout << s.count << endl;
  cout << s.currentMax << endl;
  for (int num : s.nums) {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}
