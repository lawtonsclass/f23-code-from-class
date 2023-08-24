#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
  srand(time(0)); // seed the rand # gen

  int n = rand() % 100 + 1;
  int guess = -1;

  while (guess != n) {
    // ask the user for a guess and see if it was correct
    cout << "Enter your guess: ";
    cin >> guess;
    if (guess < n) {
      cout << "Too low\n";
    } else if (guess > n) {
      cout << "Too high\n";
    } else {
      cout << "You got it!!!\n";
    }
  }

  return 0;
}
