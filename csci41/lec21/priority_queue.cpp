#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  priority_queue<int> pq;
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
