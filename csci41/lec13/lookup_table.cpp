#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
  // so much wasted memory!!! :(
  vector<string> Phonebook(10000000); 

  // insert is O(1)
  Phonebook.at(8675309) = "Lawton";
  Phonebook.at(8675310) = "Lonzo";

  // retrieve is O(1)
  cout << Phonebook.at(8675309) << endl;
  cout << Phonebook.at(8675310) << endl;


  return 0;
}
