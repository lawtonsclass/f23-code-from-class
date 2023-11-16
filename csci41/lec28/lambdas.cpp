#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void printInt(int x) { cout << x << endl; }
int inc(int x) { return x+1; }

int main() {
  vector<int> v = {1, 2, 3}; 

  for_each(v.begin(), v.end(), printInt);

  cout << endl;

  transform(v.begin(), v.end(), v.begin(), inc);
  for_each(v.begin(), v.end(), printInt);

  cout << endl;

  // [](int x) { cout << x << endl; }
  // ^ this is a function with no name that takes an int and outputs it
  for_each(v.begin(), v.end(), [](int x){ cout << x << endl; });

  transform(v.begin(), v.end(), v.begin(), [](int x){ return x*2; });
  cout << endl;
  for_each(v.begin(), v.end(), [](int x){ cout << x << endl; });

  return 0;
}
