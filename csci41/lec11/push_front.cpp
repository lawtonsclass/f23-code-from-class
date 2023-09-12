#include <iostream>
using namespace std;

template <class U>
struct Node {
  U data;
  Node* next;
};

// Node<T>*& is a reference to a pointer to a Node<T>
// (because we might need to change the values of first/last)
template <class T>
void push_front(Node<T>*& first, Node<T>*& last, T val) {
  Node<T>* newnode = new Node<T>; 
  newnode->data = val;
  newnode->next = first;
  first = newnode;

  // if the list was empty, we need to change last too
  if (last == nullptr) {
    last = newnode;
  }
}

int main() {
  // make an empty list of ints
  Node<int>* first = nullptr;
  Node<int>* last = nullptr;

  push_front<int>(first, last, 3);
  push_front<int>(first, last, 2);
  push_front<int>(first, last, 1);

  for (Node<int>* n = first; n != nullptr; n = n->next) {
    cout << n->data << " ";
  }
  cout << endl;

  return 0;
}
