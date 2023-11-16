#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
  map<string, int> phonebook;
  phonebook.emplace("Lawton", 5551234);
  phonebook.emplace("Lonzo", 5551235);

  cout << phonebook.count("Lawton") << endl; 
  cout << phonebook.count("Lawton's mom") << endl; 

  cout << phonebook.at("Lawton") << endl;
  // cout << phonebook.at("Lawton's mom") << endl;
   
  for (map<string, int>::iterator it = phonebook.begin(); it != phonebook.end(); it++) {
    cout << (*it).first << " --> " << it->second << endl;
  }

  return 0;
}
