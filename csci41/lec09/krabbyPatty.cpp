#include <iostream>
#include <list>
#include <string>
#include <vector>
using namespace std;

int main() {
  list<string> ingredients;
  // ingredients is a list, and it's initially empty
  ingredients.push_front("patty");
  ingredients.push_front("bun");
  ingredients.push_back("ketchup");
  ingredients.push_back("mustard");
  ingredients.push_back("pickles");
  ingredients.push_back("onions");
  ingredients.push_back("lettuce");
  ingredients.push_back("cheese");
  ingredients.push_back("tomatoes");
  ingredients.push_back("bun");
  // now the list holds stuff

  // convert list to a vector
  vector<string> ingredVec(ingredients.begin(), ingredients.end());
  // fills up the vector will all the stuff (from the beginning to the
  // end of ingredients)
  for (int i = 0; i < ingredVec.size(); i++) {
    cout << ingredVec.at(i) << endl;
  }
  cout << endl;

  // let's print our list using iterators
  // ingredients.end() is "one past the end of the list"
  for (list<string>::iterator it = ingredients.begin(); it != ingredients.end(); it++) {
    // *it gets the string at the current "node" the iterator is
    // pointing to
    cout << *it << endl;
  }
  cout << endl;

  // range-based for loop (note the :) goes through a container in
  // order
  for (const string& elem : ingredients) {
    cout << elem << endl;
  }
  cout << endl;

  // list<string>::iterator is a very long type to type
  // C++ can infer that type based on the return type of
  // ingredients.begin()
  for (auto it = ingredients.begin(); it != ingredients.end(); it++) {
    // *it gets the string at the current "node" the iterator is
    // pointing to
    cout << *it << endl;
  }

  return 0;
}
