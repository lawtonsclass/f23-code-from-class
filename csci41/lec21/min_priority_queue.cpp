#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/*class GreaterThan {
  public:
    bool operator()(int a, int b) {
      return a > b;
    }
};*/

template <class T>
class GreaterThan {
  public:
    bool operator()(T a, T b) {
      return a > b;
    }
};

int main() {
  // you could also just use greater<int>
  // the GreaterThan comparison class prioritizes smaller things
  priority_queue<int, vector<int>, GreaterThan<int>> pq;
  pq.push(1);
  pq.push(8);
  pq.push(-42);
  pq.push(7);
  pq.push(0);

  vector<int> sortedVec;

  // when I pop from pq, I get things in *priority* order
  while (!pq.empty()) {
    // keep popping and adding to sortedVec
    sortedVec.push_back(pq.top());
    pq.pop();
  }

  for (int x : sortedVec) {
    cout << x << " ";
  }
  cout << endl;

  return 0;
}
