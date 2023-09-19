#include <iostream>
#include <stack>
using namespace std;

class QueueUsingStacks {
  public:
    void push(int val) {
      s1.push(val); 
    }

    void pop() {
      if (s2.empty()) moveS1IntoS2();

      s2.pop();
    }

    int front() {
      if (s2.empty()) moveS1IntoS2();

      return s2.top();
    }

    bool empty() {
      return s1.empty() && s2.empty();
    }

  private:
    void moveS1IntoS2() {
      while (!s1.empty()) {
        // pop from s1 and push to s2
        s2.push(s1.top());
        s1.pop();
      }
    }

    stack<int> s1;
    stack<int> s2;
};

int main() {
  QueueUsingStacks q;
  q.push(3);
  q.push(2);
  cout << q.front() << endl;
  q.pop();
  q.push(1);
  cout << q.front() << endl;
  q.pop();
  cout << q.front() << endl;
  q.pop();
  cout << q.empty() << endl;

  return 0;
}
