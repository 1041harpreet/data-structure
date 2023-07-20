// #include <bits/stdc++.h>
// /************************************************************

//     Following is the Binary Tree node structure

//     template <typename T>
//     class TreeNode {
//         public :
//         T data;
//         TreeNode<T> *left;
//         TreeNode<T> *right;

//         TreeNode(T data) {
//             this -> data = data;
//             left = NULL;
//             right = NULL;
//         }

//         ~TreeNode() {
//             if(left)
//                 delete left;
//             if(right)
//                 delete right;
//         }
//     };

// ************************************************************/
// void inorder(TreeNode<int> *root, vector<TreeNode<int> *> &v) {
//   if (root == NULL) {
//     return;
//   }
//   inorder(root->left, v);
//   v.push_back(root);
//   inorder(root->right, v);
// }
// TreeNode<int> *flatten(TreeNode<int> *root) {
//   vector<TreeNode<int> *> v;
//   inorder(root, v);
//   TreeNode<int> *node = v[0];
//   TreeNode<int> *curr = node;
//   int j = v.size();
//   for (int i = 1; i < j; i++) {
//     TreeNode<int> *temp = v[i];
//     curr->left = NULL;
//     curr->right = temp;
//     curr = curr->right;
//   }
//   curr->left = NULL;
//   curr->right = NULL;
//   return node;
// }
