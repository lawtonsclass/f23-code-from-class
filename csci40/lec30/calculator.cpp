#include <iostream>
#include <string>
using namespace std;

class Calculator {
  public:
    Calculator();

    void pressDigit(int digit);

    void pressPlus();
    void pressMinus();
    void pressTimes();
    void pressDivide();

    int pressEnter();

  private:
    int operand1;
    int operand2;
    char operation;
    string state;
};

Calculator::Calculator() : state("first_number"), operand1(0), operand2(0) { }

void Calculator::pressDigit(int digit) {
  if (state == "first_number") {
    // add this digit to operand1
    operand1 = operand1*10 + digit;
  } else {
    // add this digit to operand2
    operand2 = operand2*10 + digit;
  }
}

void Calculator::pressPlus() {
  operation = '+';
  state = "second_number";
}

void Calculator::pressMinus() {
  operation = '-';
  state = "second_number";
}

void Calculator::pressTimes() {
  operation = '*';
  state = "second_number";
}

void Calculator::pressDivide() {
  operation = '/';
  state = "second_number";
}

int Calculator::pressEnter() {
  int result;

  // perform the operation
  if (operation == '+') {
    result = operand1 + operand2;
  } else if (operation == '-') {
    result = operand1 - operand2;
  } else if (operation == '*') {
    result = operand1 * operand2;
  } else {
    result = operand1 / operand2;
  }

  // reset the state of the calculator
  state = "first_number";
  operand1 = operand2 = 0;

  return result;
}

void assertTrue(bool b, string description) {
  if (b) {
    cout << "PASSED: " << description << endl;
  } else {
    cout << "FAILED: " << description << endl;
  }
}

void testCalculator1() {
  Calculator c;
  c.pressDigit(4);
  c.pressDigit(2);
  c.pressPlus();
  c.pressDigit(5);
  c.pressDigit(5);
  
  assertTrue(c.pressEnter() == 97, "42 + 55");
}

void testCalculator2() {
  Calculator c;
  c.pressDigit(1);
  c.pressDigit(2);
  c.pressDigit(3);
  c.pressTimes();
  c.pressDigit(4);
  c.pressDigit(5);
  c.pressDigit(6);
  
  assertTrue(c.pressEnter() == (123 * 456), "123 * 456");

  c.pressDigit(7);
  c.pressDigit(8);
  c.pressMinus();
  c.pressDigit(9);
  c.pressDigit(0);
  assertTrue(c.pressEnter() == (78 - 90), "78 - 90");
}

int main() {
  testCalculator1();
  testCalculator2();

  return 0;
}
