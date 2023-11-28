#include <iostream>
#include <vector>
using namespace std;

class RangeIterator {
 private:
  int whereAreWe;  // current spot in the range

 public:
  RangeIterator(int loc) : whereAreWe(loc) {}

  int operator*() { return whereAreWe; }

  // moves to the next value in the range
  void operator++() { whereAreWe++; }

  bool operator!=(const RangeIterator& other) {
    return whereAreWe != other.whereAreWe;
  }
};

class Range {
 private:
  int _start;
  int _end;

 public:
  RangeIterator begin() { return RangeIterator(_start); }

  RangeIterator end() {
    return RangeIterator(_end + 1);  // 1 past the end
  }

  // start out at the beginning of the range
  Range(int s, int e) : _start(s), _end(e) {}
};

class VectorIterator {
 private:
  vector<int>& v;  // reference to the vector you're iterating through
  int whereAreWe;  // curent index

 public:
  VectorIterator(vector<int>& v, int loc) : v(v), whereAreWe(loc) {}

  int operator*() { return v.at(whereAreWe); }

  void operator++() { whereAreWe++; }

  bool operator!=(const VectorIterator& other) {
    return whereAreWe != other.whereAreWe;
  }
};

VectorIterator vector_begin(vector<int>& v) { return VectorIterator(v, 0); }

VectorIterator vector_end(vector<int>& v) {
  return VectorIterator(v, v.size());  // 1 past the end
}

int main() {
  Range r(1, 5);  // we want to iterate from 1 to 5

  for (RangeIterator it = r.begin(); it != r.end(); ++it) {
    cout << *it << endl;
  }

  cout << endl;

  // equivalent to the above
  for (int i : r) {
    cout << i << endl;
  }

  // ---

  cout << endl;

  vector<int> v = {2, 3, 4};
  for (VectorIterator it = vector_begin(v); it != vector_end(v); ++it) {
    cout << *it << endl;
  }

  return 0;
}
