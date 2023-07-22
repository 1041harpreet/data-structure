#include <bits/stdc++.h>
/************************************************************

    Following is the Binary Tree node structure

    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

// 1. using brute force approach check isBSt for all node and update ans ; O(n2)
// 2. below ans :
struct Info {
  // Size of subtree
  int sz;
  // Min value in subtree
  int max;
  // Max value in subtree
  int min;
  // Size of largest BST which
  // is subtree of current node
  int ans;
  // If subtree is BST
  bool isBST;
};
Info largestBSTFast(TreeNode<int> *root) {
  if (root == NULL) {
    return {0, INT_MIN, INT_MAX, 0, true};
  }
  if (root->left == NULL && root->right == NULL) {
    return {1, root->data, root->data, 1, true};
  }
  Info ret;
  Info left = largestBSTFast(root->left);
  Info right = largestBSTFast(root->right);
  ret.sz = left.sz + right.sz + 1;
  if (left.isBST && right.isBST && left.max < root->data &&
      right.min > root->data) {
    ret.min = min(left.min, root->data);
    ret.max = max(right.max, root->data);
    ret.ans = left.ans + right.ans + 1;
    ret.isBST = true;
  }else{
  // If whole tree is not BST, return maximum
  // of left and right subtrees
  ret.ans = max(left.ans, right.ans);
  ret.isBST = false;      
  }


  return ret;
}
int largestBST(TreeNode<int> *root) { 
    return largestBSTFast(root).ans; 
    
 }
