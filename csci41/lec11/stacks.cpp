#include <iostream>
#include <stack>
using namespace std;

int main() {
  stack<int> s; 
  s.push(4);
  s.push(2);
  s.push(42);

  cout << s.top() << endl;
  s.pop();
  cout << s.top() << endl;
  s.pop();
  cout << s.top() << endl;
  s.pop();
  cout << s.empty() << endl;

  return 0;
}
