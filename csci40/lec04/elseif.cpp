#include <iostream>
#include <string>
using namespace std;

int main() {
  string day;
  cout << "Enter a day: ";
  cin >> day;

  if (day == "Monday") {
    cout << "Mon\n";
  } else {
    // it wasn't Monday--was it Tuesday, Wednesday, ...?
    if (day == "Tuesday") {
      cout << "Tue\n";
    } else {
      // it wasn't Monday or Tuesday
      if (day == "Wednesday") {
        cout << "Wed\n";
      } else {
        if (day == "Thursday") {
          cout << "Thu\n";
        } else {
          cout << "Fri\n"; // must've been Friday
        }
      }
    }
  }
  
  if (day == "Monday") {
    cout << "Mon\n";
  } else if (day == "Tuesday") {
    cout << "Tue\n";
  } else if (day == "Wednesday") {
    cout << "Wed\n";
  } else if (day == "Thursday") {
    cout << "Thu\n";
  } else {
    cout << "Fri\n"; // must've been Friday
  }

  return 0;
}
