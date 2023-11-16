#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> v = {8, 6, 7, 5}; 

  vector<int>::iterator it = v.begin();
  cout << *it << endl;
  it++;
  cout << *it << endl;

  for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;

  return 0;
}
