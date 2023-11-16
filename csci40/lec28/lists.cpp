#include <iostream>
#include <list>
using namespace std;

int main() {
  list<int> l; 
  l.push_back(3);
  l.push_back(4);
  l.push_front(2);
  l.push_front(1);

  for (list<int>::iterator it = l.begin(); it != l.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;

  for (int i : l) {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}
