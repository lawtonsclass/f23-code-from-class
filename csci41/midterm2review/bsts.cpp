#include <iostream>
using namespace std;

struct BSTNode {
  int data;
  BSTNode* left;
  BSTNode* right;
};

// search for v starting from the root
bool search(BSTNode* root, int v) {
  BSTNode* n = root;
  while (n != nullptr) {
    if (v < n->data) n = n->left; // go left (v is smaller)
    else if (v > n->data) n = n->right; // go right (v is bigger)
    else return true; // found it!
  }
  // if we get here, it wasn't in the BST :(
  return false;
}

int main() {
  BSTNode* _50 = new BSTNode; 
  BSTNode* _25 = new BSTNode; 
  BSTNode* _75 = new BSTNode; 
  BSTNode* _12 = new BSTNode; 
  BSTNode* _33 = new BSTNode; 
  _50->data = 50;
  _25->data = 25;
  _75->data = 75;
  _12->data = 12;
  _33->data = 33;

  _50->left = _25;
  _50->right = _75;
  _25->left = _12;
  _25->right = _33;
  _12->left = _12->right = nullptr;
  _33->left = _33->right = nullptr;
  _75->left = _75->right = nullptr;

  BSTNode* root = _50;

  cout << search(root, 33) << endl;
  cout << search(root, 32) << endl;
  

  return 0;
}
