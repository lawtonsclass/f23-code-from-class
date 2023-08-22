#include <iostream>
using namespace std;

int main() {
  cout << "Enter a number: ";
  int n;
  cin >> n;

  if (n % 3 == 0 && n % 5 == 0) { // this must be the first condition!
    cout << "fizzbuzz" << endl;
  } else if (n % 3 == 0) {
    cout << "fizz" << endl;
  } else if (n % 5 == 0) {
    cout << "buzz" << endl;
  } else {
    cout << n << endl;
  }

  return 0;
}
