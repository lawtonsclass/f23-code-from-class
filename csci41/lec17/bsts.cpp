#include <iostream>
using namespace std;

struct TreeNode {
  int data;
  TreeNode* left; // potentially your left child
  TreeNode* right; // no child if null
  TreeNode* parent;
};

bool search(TreeNode* root, int key) {
  TreeNode* n = root; // start our node pointer at the root

  while (n != nullptr) {
    // look at n->data, and see if we need to go left or right
    if (key < n->data) {
      // go left
      n = n->left;
    } else if (key > n->data) {
      // go right
      n = n->right;
    } else {
      // found it!
      return true;
    }
  }

  // if we got here, n = nullptr, so we didn't find the key :(
  return false;
}

// it's possible that the root of the tree will change after an
// insert, so we need to pass the root by reference
void insert(TreeNode*& root, int key) {
  TreeNode* newNode = new TreeNode;  
  newNode->data = key;
  newNode->left = newNode->right = nullptr;
  newNode->parent = nullptr;

  // empty tree case
  if (root == nullptr) {
    // the newNode is the new root
    root = newNode;
    return;
  }

  TreeNode* n = root; // start our node pointer at the root
  while (n != nullptr) {
    // look at n->data, and see if we need to go left or right
    if (key < n->data) {
      // go left if we can
      if (n->left != nullptr) {
        n = n->left;
      } else {
        // we found the place to insert!!!
        n->left = newNode;
        newNode->parent = n;
        return;
      }
    } else if (key > n->data) {
      // go right if we can
      if (n->right != nullptr) {
        n = n->right;
      } else {
        n->right = newNode;
        newNode->parent = n;
        return;
      }
    } else {
      // found it--it's already in the tree
      delete newNode; // let's not leak memory lol
      return;
    }
  }
}

int main() {
  TreeNode* root = nullptr;
  insert(root, 7);
  insert(root, 3);
  insert(root, 42);
  insert(root, 4);
  insert(root, 5);

  cout << root->data << endl;
  cout << root->right->data << endl;
  cout << root->left->right->right->data << endl;

  return 0;
}
