#include <iostream>
#include <list>
using namespace std;

int main() {
  list<double> l;  
  l.push_back(3.14);
  l.push_back(5.67);
  // the list looks like [3.14, 5.67]
  cout << l.front() << endl;

  // iterate through l with "iterators"
  for (list<double>::iterator it = l.begin(); it != l.end(); it++) {
    // it is like a pointer to the current element of the list
    cout << *it << " ";
  }
  cout << endl;

  return 0;
}
