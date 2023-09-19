#include <iostream>
using namespace std;

int harryPotter = 42; // this is a *global* variable -- it lives for the life of the program

void gobletOfFire() {
  int cedric = 8; // this is a *local* variable -- it lives only as long as the function lives
  cedric++;
  cout << cedric << endl;

  harryPotter++;
  cout << harryPotter << endl;
}

int main() {
  gobletOfFire();

  harryPotter++;
  cout << harryPotter << endl;

  // cout << cedric << endl; // cedric is already dead :(

  return 0;
}
