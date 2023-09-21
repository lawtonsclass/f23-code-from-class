#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
  deque<string> d;
  d.push_back("hello");
  d.push_front("hi");
  d.push_back("world");
  cout << d.front() << endl;
  cout << d.back() << endl;

  for (deque<string>::iterator it = d.begin(); it != d.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;

  return 0;
}
