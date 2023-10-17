#include <iostream>
#include <vector>
using namespace std;

int findMax(const vector<int>& v) {
  return v.at(0);  // in a max heap, index 0 is always the max!
}

int getParentValue(const vector<int>& v, int idx) {
  return v.at((idx - 1) / 2);
}

// v is the heap, startingIdx is the index of the node that's in the
// wrong spot
void bubbleDown(vector<int>& v, int startingIdx) {
  // look at the children, and figure out which one to swap with
  int currentIndex = startingIdx;
  while (true) {
    int currentKey = v.at(currentIndex);

    // we have to look left and right if possible
    int leftIndex = currentIndex * 2 + 1;
    if (leftIndex >= v.size()) break;  // we're a leaf--stop

    // if we got this far, we know we at least have a left key
    int leftKey = v.at(leftIndex);

    int rightIndex = currentIndex * 2 + 2;
    int rightKey;
    if (rightIndex < v.size()) rightKey = v.at(rightIndex);

    // if neither child is bigger, we're done
    // (i.e., we're >= to them)
    // again, there might not be a right child
    if (leftKey <= currentKey &&
        (rightIndex >= v.size() || rightKey <= currentKey))
      break;

    // swap with the bigger one
    if (rightIndex >= v.size() || leftKey > rightKey) {
      cout << "swapping with left: ";
      cout << "current index: " << currentIndex << endl;
      cout << "left/right keys: " << leftKey << " " << rightKey << endl;
      // either the right index doesn't exist, or the left key is
      // bigger than the right
      // swap with left
      v.at(currentIndex) = leftKey;
      v.at(leftIndex) = currentKey;
      // our current index has changed
      currentIndex = leftIndex;
    } else {
      // swap with right
      cout << "swapping with right: ";
      cout << "current index: " << currentIndex << endl;
      cout << "left/right keys: " << leftKey << " " << rightKey << endl;
      v.at(currentIndex) = rightKey;
      v.at(rightIndex) = currentKey;
      // our current index has changed
      currentIndex = rightIndex;
    }
  }
}

int main() {
  vector<int> h = {100, 0, 36, 17, 3, 25, 1, 2, 7};

  bubbleDown(h, 1);  // move the 0 to where it belongs in the heap

  cout << findMax(h) << endl;
  cout << getParentValue(h, 3) << endl;

  for (int x : h) {
    cout << x << " ";
  }
  cout << endl;

  return 0;
}
