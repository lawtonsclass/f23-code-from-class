#include <iostream>
#include <stdexcept> // for runtime_error
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

void throwString() {
  string s = "blah";
  throw s;
}

void throwInt() {
  throw 42;
}

void throwRuntimeError() {
  runtime_error re("Uh oh!");
  throw re;
}

void doStuff() {
  int choice = rand() % 3;

  try {
    if (choice == 0) {
      throwInt();
    } else if (choice == 1) {
      throwString();
    } else {
      throwRuntimeError();
    }
  } catch (runtime_error& e) {
    // I know how to handle a runtime_error exception!
    cout << "Caught a runtime_error in doStuff: " << e.what() << endl;
  } catch (string& s) {
    // I know how to handle a string exception!
    cout << "Caught a string in doStuff: " << s << endl;
  }
}


int main() {
  srand(time(0));

  try {
    // the very first exception gets handled, and that's the end of
    // the entire try/catch
    doStuff();
  } catch (runtime_error& e) {
    // I know how to handle a runtime_error exception!
    cout << "Caught a runtime_error in main: " << e.what() << endl;
  } catch (string& s) {
    // I know how to handle a string exception!
    cout << "Caught a string in main: " << s << endl;
  } catch (int& i) {
    // I know how to handle an int exception!
    cout << "Caught an int in main: " << i << endl;
  }

  cout << "Rest of the program...\n";

  return 0;
}
