#include <iostream>
#include <fstream>
using namespace std;

int main() {
  // ofstream ofs("1to10.txt");

  // these two lines are equivalent to the line above
  ofstream ofs;
  ofs.open("1to10.txt");

  for (int i = 1; i <= 10; i++) {
    ofs << i << endl;
  }

  // it's good practice to "close" the file as soon as you're done
  // working on it
  ofs.close();

  return 0;
}
