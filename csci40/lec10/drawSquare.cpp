#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char* argv[]) {
  if (argc != 2) {
    cout << "Must run with a single number!\n";
    cout << "Usage: " << argv[0] << " n, where n is a number\n";
    // stop the program
    exit(0);
  }

  int width = atoi(argv[1]);
  
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < width; j++) {
      cout << "*";
    }
    cout << endl;
  }

  return 0;
}
