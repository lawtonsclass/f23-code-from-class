#include <iostream>
#include <vector>
using namespace std;

int main() {
  // int arr[] = {1, 2, 3};
  vector<int> v = {1, 2, 3};
  cout << v.at(0) << " ";
  cout << v.at(1) << " ";
  cout << v.at(2) << "\n";

  vector<int> v2; // v2 is an empty vector of ints
  v2.push_back(1);
  v2.push_back(2);
  v2.push_back(3);
  cout << v2.at(0) << " ";
  cout << v2.at(1) << " ";
  cout << v2.at(2) << "\n";

  vector<int> v3;
  while (true) {
    cout << "Enter a number to add to v3: ";
    int n;
    cin >> n;

    if (n == -1) {
      break;
    }

    v3.push_back(n);
  }

  // iterate through v3 and visit every index
  for (int i = 0; i < v3.size(); i++) {
    cout << v3.at(i) << " ";
  }
  cout << endl;


  return 0;
}
