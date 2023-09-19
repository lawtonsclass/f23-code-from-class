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

void test_counter() {
  init_counter(); 
  inc();
  inc();
  inc();
  dec();
  assertTrue(get_count() == 2, "counter test");
}

int main() {
  test_counter();

  // init_counter(); 
  // inc();
  // inc();
  // inc();
  // dec();
  // cout << get_count() << endl;

  return 0;
}
