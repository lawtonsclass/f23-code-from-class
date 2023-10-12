#include <iostream>
#include <fstream>
using namespace std;

int main() {
  ofstream ofs;
  ofs.open("1to10.txt", ios_base::app);

  ofs << 11 << endl;

  // it's good practice to "close" the file as soon as you're done
  // working on it
  ofs.close();

  return 0;
}
