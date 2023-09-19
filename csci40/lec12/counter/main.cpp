#include <iostream>
#include <string>
#include "counter.h"
using namespace std;

void assertTrue(bool b, string description) {
  if (b) {
    cout << "PASSED: " << description << endl;
  } else {
    cout << "FAILED: " << description << endl;
  }
}

int main() {
  init_counter(); 
  inc();
  inc();
  inc();
  dec();
  cout << get_count() << endl;

  return 0;
}
