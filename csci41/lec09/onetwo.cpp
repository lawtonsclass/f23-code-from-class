#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next;
};

int main() {
  Node* one = new Node; 
  Node* two = new Node; 

  one->data = 1;
  two->data = 2;

  one->next = two;
  two->next = nullptr; // the last element of the list

  Node* first = one;
  Node* last = two;

  return 0;
}
