#include <iostream>
using namespace std;

int main() {
  cout << "Enter a grade: ";
  double grade;
  cin >> grade;

  if (grade >= 90.0) {
    cout << "A\n";
  } else if (grade >= 80.0) {
    cout << "B\n";
  } else if (grade >= 70.0) {
    cout << "C\n";
  } else if (grade >= 60.0) {
    cout << "D\n";
  } else {
    cout << "F\n";
  }

  return 0;
}
