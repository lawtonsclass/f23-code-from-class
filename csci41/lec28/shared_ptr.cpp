#include <iostream>
#include <memory>
using namespace std;

int main() {
  shared_ptr<int> sp1 = make_shared<int>(42);  
  cout << "reference count: " << sp1.use_count() << endl;
  shared_ptr<int> sp2 = sp1;
  cout << "reference count: " << sp1.use_count() << endl;
  cout << "reference count: " << sp2.use_count() << endl;

  cout << *sp1 << endl;
  cout << *sp2 << endl;

  return 0;
}
