#include <iostream>
#include <stack>
using namespace std;

int main() {
  stack<int> operandStack; 
  
  while (true) {
    cout << "Enter n to type a number, o for an operator, or q to quit: ";
    char c;
    cin >> c;

    if (c == 'n') {
      int n;
      cout << "Enter the number: ";
      cin >> n;

      operandStack.push(n);
    } else if (c == 'o') {
      char o;
      cout << "Enter the operator: ";
      cin >> o;

      // get the two operands off the stack
      int n2 = operandStack.top(); // second operand is higher on the stack than the first
      operandStack.pop();
      int n1 = operandStack.top();
      operandStack.pop();

      // perform the operation o
      if (o == '+') {
        operandStack.push(n1 + n2);
      } else if (o == '-') {
        operandStack.push(n1 - n2);
      } else if (o == '*') {
        operandStack.push(n1 * n2);
      } else { // (division)
        operandStack.push(n1 / n2);
      }
    } else { // assume it was 'q'
      break;
    }
  }

  // display the answer after the user typed q
  // it's on the top of the stack
  cout << "result: " << operandStack.top() << endl;
  // optionally, you could throw an error if the stack has more than
  // one thing on it (or is empty)

  return 0;
}
