#include <iostream>
using namespace std;

int main() {
  int arr[10]; // arr is an array of 10 ints
  // the valid indices are 0-9

  // get 10 nums from the user and put them into arr
  for (int i = 0; i < 10; i++) {
    // i is the current index of arr I'm trying to fill
    cout << "Enter the next element: ";
    int nextElement;
    cin >> nextElement;
    arr[i] = nextElement;
  }

  // print out all the elems of arr
  for (int i = 0; i < 10; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  // sum all the elems of arr
  int sum = 0;
  for (int j = 0; j < 10; j++) {
    sum += arr[j];
  }
  cout << "Sum: " << sum << endl;
  cout << "Average: " << sum / 10.0 << endl;

  // get the min element
  int min = arr[0]; // guess that arr[0] is the real min 
  for (int i = 1; i < 10; i++) {
    // update min if we see a smaller element
    if (arr[i] < min) {
      min = arr[i]; // arr[i] is smaller -- it's a better guess for the min!
    }
  }
  // after we visit every element, min holds the true minimum element
  // in arr
  cout << "Min: " << min << endl;

  return 0;
}
