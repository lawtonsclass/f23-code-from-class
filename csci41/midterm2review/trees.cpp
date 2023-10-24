#include <iostream>
using namespace std;

struct TreeNode {
  int data;
  TreeNode* left;
  TreeNode* right;
};

// see if v exists somewhere in the tree
bool search(TreeNode* root, int v) {
  if (root == nullptr) {
    // base case: empty tree--v can't possibly be there!
    return false;
  } else {
    // recursive case--if v is in this tree, it's either to the left,
    // to the right, or it's our root's node
    bool wasItToTheLeft = search(root->left, v);
    bool wasItToTheRight = search(root->right, v);
    bool wasItTheRoot = root->data == v;
    return wasItToTheLeft || wasItToTheRight || wasItTheRoot;
  }
}

void deleteTree(TreeNode* root) {
  if (root == nullptr) {
    // empty tree; nothing to delete
    return;
  } else {
    // recursively delete the left subtree
    deleteTree(root->left);
    // recursively delete the right subtree
    deleteTree(root->right);
    // delete the root node
    cout << "about to delete the " << root->data << " node\n";
    delete root;
    // a postorder traversal!
  }
}

void preOrder(TreeNode* root) {
  if (root == nullptr) {
    // no node to visit
    return;
  } else {
    // visit root
    cout << root->data << endl;
    // visit left
    preOrder(root->left);
    // visit right
    preOrder(root->right);
  }
}

int main() {
  TreeNode* one = new TreeNode; 
  TreeNode* two = new TreeNode; 
  TreeNode* three = new TreeNode; 
  TreeNode* four = new TreeNode; 
  TreeNode* five = new TreeNode; 
  one->data = 1;
  two->data = 2;
  three->data = 3;
  four->data = 4;
  five->data = 5;

  one->left = two;
  one->right = three;
  two->left = four;
  two->right = five;

  three->left = three->right = nullptr;
  four->left = four->right = nullptr;
  five->left = five->right = nullptr;

  TreeNode* root = one;

  cout << root->data << endl;
  cout << root->left->data << endl;
  cout << root->right->data << endl;
  cout << root->left->left->data << endl;
  cout << root->left->right->data << endl;

  cout << endl;
  
  cout << search(root, 4) << endl;
  cout << search(root, 1) << endl;
  cout << search(root, 7) << endl;

  cout << endl;
  preOrder(root);

  cout << endl;
  deleteTree(root);

  return 0;
}
