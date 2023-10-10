#include <iostream>
using namespace std;

int* make_new_int_on_the_heap() {
  int* n = new int; // makes space for one int on the heap, and save
                    // the addr of it into n

  *n = 42;

  cout << *n << endl;

  return n;
}

int main() {
  int* p = make_new_int_on_the_heap();

  *p = *p + 1;

  cout << *p << endl;

  // once you're done with heap memory, make sure to delete it!
  delete p;

  return 0;
}
