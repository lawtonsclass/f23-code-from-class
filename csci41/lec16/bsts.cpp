#include <iostream>
using namespace std;

struct TreeNode {
  int data;
  TreeNode* left; // potentially your left child
  TreeNode* right; // no child if null
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

int main() {
  TreeNode* five = new TreeNode; 
  TreeNode* three = new TreeNode; 
  TreeNode* ten = new TreeNode; 
  TreeNode* one = new TreeNode; 
  TreeNode* four = new TreeNode; 
  TreeNode* fortyTwo = new TreeNode; 

  five->data = 5;
  three->data = 3;
  ten->data = 10;
  one->data = 1;
  four->data = 4;
  fortyTwo->data = 42;

  five->left = three;
  five->right = ten;
  three->left = one;
  three->right = four;
  ten->left = nullptr;
  ten->right = fortyTwo;
  one->left = one->right = nullptr;
  four->left = four->right = nullptr;
  fortyTwo->left = fortyTwo->right = nullptr;

  TreeNode* root = five;

  cout << search(root, 42) << endl;
  cout << search(root, 7) << endl;

  return 0;
}
