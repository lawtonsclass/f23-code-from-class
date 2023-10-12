#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
  ofstream ofs("out.txt", ios_base::app);

  while (true) {
    string line;
    cout << "Enter a line: ";
    getline(cin, line);

    if (line == "q") {
      break;
    }

    // add this line to the file
    ofs << line << endl;
  }

  ofs.close();

  return 0;
}
