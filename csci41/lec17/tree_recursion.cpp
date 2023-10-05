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

// root is the root of the *current subtree*
int sum(TreeNode* root) {
  if (root == nullptr) {
    // base case--empty tree
    return 0;
  } else {
    // recursive case
    return sum(root->left) + sum(root->right) + root->data;
  }
}

void inorder(TreeNode* root) {
  if (root == nullptr) {
    // base case--empty tree: do not
    return;
  } else {
    // recurse left
    inorder(root->left);
    // print root's data
    cout << root->data << " ";
    // recurse right
    inorder(root->right);
  }
}

int depth(TreeNode* n) {
  if (n->parent == nullptr) {
    // base case--we're at the root of the tree: depth is 0
    return 0;
  } else {
    // we have a parent, so we can recurse
    // get the depth of our parent recursively
    int depthOfParent = depth(n->parent);
    // our original node's depth is one more than its parent's depth
    return 1 + depthOfParent;
  }
}

int main() {
  TreeNode* root = nullptr;
  insert(root, 7);
  insert(root, 5);
  insert(root, 8);
  insert(root, 3);
  insert(root, 6);
  insert(root, 10);

  cout << sum(root) << endl;

  inorder(root);
  cout << endl;

  TreeNode* ten = root->right->right;
  cout << depth(ten) << endl;
  cout << depth(root) << endl;
  cout << depth(root->left) << endl;


  return 0;
}
