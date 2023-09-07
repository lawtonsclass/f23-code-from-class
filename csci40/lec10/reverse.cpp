#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> v = {1, 2, 3, 4, 5, 6, 7}; 

  // this loop will iterate size / 2 times!
  for (int i = 0; i < v.size() / 2; i++) {
    // swap indices i and size - 1 - i
    int indexToSwapWith = v.size() - 1 - i;

    int temp = v.at(i);
    v.at(i) = v.at(indexToSwapWith);
    v.at(indexToSwapWith) = temp;
  }

  for (int e : v) {
    cout << e << " ";
  }
  cout << endl;

  return 0;
}
