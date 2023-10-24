#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

int main() {
  vector<int> v = {1, 2, 3}; 
  vector<int> v_reversed;

  stack<int> s;
  for (int x : v) {
    s.push(x);
  }
  while (!s.empty()) {
    v_reversed.push_back(s.top());
    s.pop();
  }

  for (int x : v_reversed) {
    cout << x << " ";
  }
  cout << endl;

  /////////////////////////////////

  queue<double> q;
  q.push(4);
  q.push(5);
  q.push(6);
  // | 4 5 6 |
  // ^ front ^ back
  while (!q.empty()) {
    cout << q.front() << " ";
    q.pop();
  }
  cout << endl;

  return 0;
}
