#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(int argc, char* argv[]) {
  string input_filename = argv[1];
  string output_filename = argv[2];

  ifstream ifs(input_filename);
  ofstream ofs(output_filename);

  while (true) {
    // read a char from ifs
    char c = ifs.get();
    // make sure we got a valid char before we write it
    if (ifs.eof()) {  // if (!ifs) also works
      break;
    }
    // put the char into ofs
    ofs.put(c);
  }

  ifs.close();
  ofs.close();

  return 0;
}
