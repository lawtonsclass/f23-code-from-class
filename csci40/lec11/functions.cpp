#include <iostream>
#include <string>
using namespace std;

int add(int x, int y) {
  // give back (i.e., return) the sum of x and y
  return x + y;
}

double add(double x, double y) {
  // give back (i.e., return) the sum of x and y
  return x + y;
}

string add(string x, string y) {
  // give back (i.e., return) the sum of x and y
  return x + y;
}

void printHello() {
  cout << "Hello!" << endl;
}

int main() {
  cout << add(4, 5) << endl;
  cout << add(1, 7) << endl;

  cout << add(3.14, 5.67) << endl;

  string s1 = "hi ";
  string s2 = "mom!";
  cout << add(s1, s2) << endl;

  printHello();
  printHello();
  printHello();


  return 0;
}
