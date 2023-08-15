#include <iostream>
#include <sstream>
using namespace std;

int main() {
  stringstream ss; 

  // you can put stuff inside the stuff inside the stringstream,
  // pretending that it's cout/a file
  ss << 42 << " ";
  ss << "blah" << " ";
  ss << 3.14 << endl;

  // ss.str() = "42 blah 3.14\n";

  // you can extract from the string that you've built
  int x;
  ss >> x;
  cout << x << endl;

  // get the entire built-up string with .str()
  cout << ss.str();

  return 0;
}
