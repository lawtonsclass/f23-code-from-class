#include <iostream>
using namespace std;

class HolderArr {
  public:
    HolderArr(int n) {
      arr = new int[n];
      size = n;
    }

    HolderArr(const HolderArr& other) {
      // deep copy other's arr
      size = other.size;
      arr = new int[size];

      for (int i = 0; i < size; i++)
        arr[i] = other.arr[i];
    }

    HolderArr& operator=(const HolderArr& other) {
      // watch out for self assignment
      if (&other == this) return *this;

      // delete our own array
      delete[] arr;

      // deep copy other's stuff into ourselves
      size = other.size;
      arr = new int[size];

      for (int i = 0; i < size; i++)
        arr[i] = other.arr[i];

      return *this;
    }

    ~HolderArr() {
      // delete arr
      delete[] arr;
    }

  private:
    int* arr;
    int size;
};

int main() {
  HolderArr h(42);
  HolderArr h2(h); // copy constructor
  HolderArr h3(43);
  h3 = h2; // copy assignment
  h2 = h2; // copy assignment

  return 0;
}
