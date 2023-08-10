#include <iostream>
using namespace std;

int main() {
  cout << 'A' << endl;
  cout << static_cast<int>('A') << endl;

  cout << static_cast<char>('A' + 2) << endl;

  return 0;
}
