#include <iostream>
#include <string>
using namespace std;

void orderPizza(const string& type) {
  if (type == "pineapple") {
    throw runtime_error("Pineapple is not allowed on a pizza!!! >:("); 
  }

  cout << "here is a " << type << " pizza\n";
}

int main() {
  cout << "What kind of pizza do you want? ";
  string pizza_type;
  cin >> pizza_type;

  try {
    // C++, please try to execute the following function, and stop if
    // an exception is thrown
    orderPizza(pizza_type);
    // ...
  } catch (runtime_error& e) {
    // if we get here, a runtime_error was thrown
    cout << "Uh oh...\n";
    cout << e.what() << endl;
    cout << "Re-run the program and try again!\n";
  } catch (int& i) {
    // handle the int i being thrown...
  }

  return 0;
}
