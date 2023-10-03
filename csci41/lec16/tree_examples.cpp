#include <iostream>
using namespace std;

struct TreeNode {
  int data;
  TreeNode* left; // potentially your left child
  TreeNode* right; // no child if null
  TreeNode* parent;
};

int main() {
  TreeNode* fortyTwo = new TreeNode; 
  TreeNode* three = new TreeNode; 
  TreeNode* four = new TreeNode; 
  TreeNode* seven = new TreeNode; 

  fortyTwo->data = 42;
  three->data = 3;
  four->data = 4;
  seven->data = 7;

  fortyTwo->left = three;
  fortyTwo->right = four;
  three->left = nullptr;
  three->right = nullptr;
  four->left = seven;
  four->right = nullptr;
  seven->left = nullptr;
  seven->right = nullptr;

  fortyTwo->parent = nullptr;
  three->parent = fortyTwo;
  four->parent = fortyTwo;
  seven->parent = four;

  TreeNode* root = fortyTwo;

  cout << root->data << endl;
  cout << root->left->data << endl;
  cout << root->right->data << endl;
  cout << root->right->left->data << endl;

  return 0;
}
