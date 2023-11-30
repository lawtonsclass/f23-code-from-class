#include <iostream>
using namespace std;

struct TreeNode {
  int data;
  TreeNode* left;
  TreeNode* right;
};

int count_leaves(TreeNode* root) {
  if (root == nullptr) return 0;
  else if (root->left == nullptr && root->right == nullptr) return 1;
  else return count_leaves(root->left) + count_leaves(root->right);
}

int main() {
  TreeNode* five = new TreeNode; 
  TreeNode* three = new TreeNode; 
  TreeNode* eight = new TreeNode; 
  TreeNode* one = new TreeNode; 
  TreeNode* seven = new TreeNode; 
  TreeNode* nine = new TreeNode; 
  five->data = 5;
  three->data = 3;
  eight->data = 8;
  one->data = 1;
  seven->data = 7;
  nine->data = 9;
  five->left = three;
  five->right = eight;
  three->left = one;
  three->right = nullptr;
  one->left = one->right = nullptr;
  eight->left = seven;
  eight->right = nine;
  seven->left = seven->right = nullptr;
  nine->left = nine->right = nullptr;

  TreeNode* root = five;

  cout << count_leaves(root) << endl;

  return 0;
}
