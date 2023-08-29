#include <iostream>
using namespace std;

int main() {
  for (int i = 0;  i <= 1001; i++) {
    cout << "Day " << i << ":\n";
    cout << "  rabbit As: " << (2000*i) << endl;
    cout << "  rabbit Bs: " << (2*i*i) << endl;
    cout << endl;
  }

  return 0;
}
