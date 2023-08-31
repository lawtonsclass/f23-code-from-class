#include <iostream>
#include <ctime>
using namespace std;

int main() {
  clock_t start = clock();

  // insert complicated task here...
  int sum = 0;
  for (int i = 0; i < 100'000'000; i++) {
    sum += i;
  } 

  clock_t end = clock();
  double secondsInBetween = static_cast<double>(end - start) / CLOCKS_PER_SEC;

  cout << secondsInBetween << endl;

  return 0;
}

