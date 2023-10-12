#include <iostream>
#include <fstream>
using namespace std;

int main() {
  ifstream ifs("1to10.txt"); 

  int sum = 0;
  for (int i = 0; i < 5; i++) {
    int nextNum;
    ifs >> nextNum;
    sum += nextNum;
  }

  ifs.close(); // I don't need ifs anymore!

  cout << "sum: " << sum << endl;

  return 0;
}
