#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> v; // starts off empty
  cout << v.size() << endl; // 0
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  cout << v.size() << endl; // 3

  for (int i = 0; i < v.size(); i++) {
    cout << v.at(i) << " ";
  }
  cout << endl;

  return 0;
}
