#include <iostream>
#include <list>
#include <string>
#include <vector>
using namespace std;

struct Pair {
  string key;
  int val;
  bool hasThisElementBeenDeleted = false;
  bool isThereAValueHereRightNow = false;
};

const int c1 = 5;
const int c2 = 7;

int hashString(const string& s) { return 0; }

void insertIntoHashTable(vector<Pair>& v, const string& key, int val) {
  // try the normal hashed key as the index, and see if there's
  // something there
  int H = hashString(key);
  int idx = H;  // idx will be the index that I'm currently considering
  int i = 0;

  // check and see if this index is taken or if the key already exists
  // in the table
  while (v.at(idx).isThereAValueHereRightNow && v.at(idx).key != key) {
    // change idx to be some other one
    i++;
    idx = (H + c1 * i + c2 * i * i) % 11;
  }

  // insert at the empty spot or overwrite the existing key
  v.at(idx).key = key;
  v.at(idx).val = val;
  v.at(idx).isThereAValueHereRightNow = true;
}

// return -1 if not found
int lookupInHashTable(vector<Pair>& v, const string& key) {
  // try the normal hashed key as the index, and see if there's
  // something there
  int H = hashString(key);
  int idx = H;  // idx will be the index that I'm currently considering
  int i = 0;

  // check and see if this index is in use and not equal to the key
  // we're searching for
  while (v.at(idx).isThereAValueHereRightNow && v.at(idx).key != key) {
    // change idx to be some other one
    i++;
    idx = (H + c1 * i + c2 * i * i) % 11;
  }

  // once this while loop stops, either we found it or we didn't
  if (v.at(idx).key == key)
    return v.at(idx).val;
  else
    return -1;
}

int main() {
  // we're going to find a new index for every separate key
  vector<Pair> v(11);  // my hash table

  insertIntoHashTable(v, "Mom", 5555555);
  insertIntoHashTable(v, "Lawton", 8675309);

  cout << lookupInHashTable(v, "Mom") << endl;
  cout << lookupInHashTable(v, "Lawton") << endl;
  cout << lookupInHashTable(v, "Lawton's cat") << endl;

  insertIntoHashTable(v, "Lawton", 8675310);
  cout << lookupInHashTable(v, "Lawton") << endl;

  return 0;
}
