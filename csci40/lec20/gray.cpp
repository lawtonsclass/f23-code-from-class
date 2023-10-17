// future Lawton: install eog if your VM won't load the image

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
  ifstream ifs("cat.ppm");
  ofstream ofs("cat-gray.ppm");

  // keep the same first 3 lines in the output image
  string line;
  getline(ifs, line);
  ofs << line << endl;
  getline(ifs, line);
  ofs << line << endl;
  getline(ifs, line);
  ofs << line << endl;

  // repeatedly read rgb values and modify them
  int r, g, b;
  while (ifs >> r >> g >> b) {
    // convert to grayscale and add it to the output image 
    int avg = (r + g + b) / 3;
    ofs << avg << " " << avg << " " << avg << endl;
  }

  ifs.close();
  ofs.close();

  return 0;
}
