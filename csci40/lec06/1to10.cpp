#include <iostream>
using namespace std;

int main() {
  int i = 1;
  while (i <= 10) {
    cout << i << endl; // print i
    i++; // increment i by 1
  }

  cout << endl;

  int j = 1;
  int sum = 0; // repeatedly add j into sum 10 times (and increment j each time)
  while (j <= 10) {
    sum = sum + j; // adds 1 the first time, 2 the second, 3 the third time, ...
    j++;
  }

  cout << sum << endl;

  cout << endl;

  i = 10;
  while (i >= 0) {
    cout << i << endl;
    i = i - 2;
  }

  return 0;
}
