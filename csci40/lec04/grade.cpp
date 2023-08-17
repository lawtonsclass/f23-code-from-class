#include <iostream>
using namespace std;

int main() {
  double grade;
  cout << "Enter a grade: ";
  cin >> grade;

  // convert grade to "A", "C", or "F"
  if (grade >= 90.0) {
    cout << "A\n";
  } else if (grade >= 70.0) {
    cout << "C\n";
  } else {
    cout << "F\n";
  }

  return 0;
}
