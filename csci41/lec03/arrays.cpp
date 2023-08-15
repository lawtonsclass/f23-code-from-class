#include <iostream>
using namespace std;

int main() {
  int arr[] = {1, 2, 3};
  cout << arr << endl;
  cout << &arr[0] << endl;
  cout << *arr << endl;
  cout << *(arr + 1) << endl; // equivalent to arr[1]

  return 0;
}
