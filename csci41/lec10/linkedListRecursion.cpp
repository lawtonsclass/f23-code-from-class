#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next;
};

void printInOrder(Node* n) {
  if (n == nullptr) {
    // base case: empty list
    // do nothing
  } else {
    // recursive case
    // print the first node's data
    cout << n->data << endl;
    // recursively print the smaller list
    printInOrder(n->next);
  }
}

void printReverse(Node* n) {
  if (n == nullptr) {
    // base case: empty list
    // do nothing
  } else {
    // recursive case
    // recursively print the smaller list in reverse
    printReverse(n->next);
    // print the first node's data
    cout << n->data << endl;
  }
}

// search the list starting from Node n for val
bool search(Node* n, int val) {
  if (n == nullptr) {
    return false;
  } else {
    // recursive case: non-empty list
    // either val is in the smaller list, or it's in the first Node
    bool wasItInTheRestOfTheList = search(n->next, val);
    bool wasItInTheFirstNode = n->data == val;
    return wasItInTheRestOfTheList || wasItInTheFirstNode;
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
  three->next = nullptr; // last element of the list

  Node* first = one;
  Node* last = three;
  
  printInOrder(first); // lists are represented with ptrs to their first Node
                       
  cout << endl;

  printReverse(first);

  cout << endl;

  cout << search(first, 1) << endl;
  cout << search(first, 2) << endl;
  cout << search(first, 3) << endl;
  cout << search(first, 4) << endl;

  return 0;
}
