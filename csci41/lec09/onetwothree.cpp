#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next;
};

int main() {
  Node* one = new Node; 
  Node* two = new Node; 
  Node* three = new Node; 

  one->data = 1;
  two->data = 2;
  three->data = 3;

  one->next = two;
  two->next = three;
  three->next = nullptr; // the last element of the list

  Node* first = one;
  Node* last = three;

  // let's iterate
  Node* n = first;
  while (n != nullptr) {
    // print data
    cout << n->data << " ";
    // advance n
    n = n->next;
  }
  cout << endl;

  // for loop version!
  for (Node* m = first; m != nullptr; m = m->next) {
    cout << m->data << " ";
  }
  cout << endl;

  return 0;
}
