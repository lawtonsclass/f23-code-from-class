#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
  srand(time(0)); // seed the random # gen with the current time

  cout << RAND_MAX << endl; 
  cout << rand() << endl;
  cout << rand() << endl;
  cout << rand() << endl;

  cout << "Enter a number: ";
  int n;
  cin >> n;

  // calculate a random number between 1 and n
  cout << (rand() % n) + 1 << endl;

  char c1 = rand() % 128; // 0 - 127
  char c2 = rand() % 128; // 0 - 127
  char c3 = rand() % 128; // 0 - 127

  cout << c1 << c2 << c3 << endl;

  return 0;
}
