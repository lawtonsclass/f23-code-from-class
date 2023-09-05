#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<double> v = {1.5, 2.75, 3.14};

  for (int i = 0; i < v.size(); i++) {
    cout << v.at(i) << " ";
  }
  cout << endl;
  
  // range-based for loop
  for (double elem : v) {
    cout << elem << " ";
  }
  cout << endl;

  return 0;
}
