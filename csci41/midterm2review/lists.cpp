#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next;
};

// recursively search through the list (starting at first) for v
bool search(Node* first, int v) {
  if (first == nullptr) {
    // base case: emtpy list
    // v can't possibly be here!
    return false;
  } else {
    // recursive case
    // either v is in the rest of the list, or it's the first->data
    bool wasItInTheRest = search(first->next, v);
    bool wasItInFirst = v == first->data;
    return wasItInTheRest || wasItInFirst;
  }
}

void deleteList(Node* first) {
  if (first == nullptr) {
    // base case: emtpy list
    // no nodes to delete
    return;
  } else {
    // recursive case: we have a smaller list to delete, as well as
    // first itself
    deleteList(first->next);
    cout << "about to delete the " << first->data << " node!\n";
    delete first;
  }
}

int main() {
  Node* one = new Node; 
  Node* two = new Node; 
  Node* three = new Node; 
  one->data = 1;
  two->data = 2;
  three->data = 3;
  one->next = two;
  two->next = three;
  three->next = nullptr;

  Node* first = one;
  Node* last = three;

  // add 1 to every Node
  for (Node* n = first; n != nullptr; n = n->next) {
    n->data = n->data + 1;
  }

  // print out the list
  for (Node* n = first; n != nullptr; n = n->next) {
    cout << n->data << " ";
  }
  cout << endl;

  cout << search(first, 3) << endl;
  cout << search(first, 4) << endl;
  cout << search(first, 1) << endl;

  deleteList(first);

  return 0;
}
