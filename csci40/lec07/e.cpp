#include <iostream>
using namespace std;

double factorial(int n) {
  double result = 1.0; 

  for (int i = 1; i <= n; i++) {
    result = result * i;
  } 

  return result;
}

int main() {
  double sum = 0.0;
  
  for (int n = 0; n <= 100; n++) {
    double currentTerm = 1.0 / factorial(n);
    sum += currentTerm; // short for sum = sum + currentTerm;
  }

  cout << sum << endl;

  return 0;
}
