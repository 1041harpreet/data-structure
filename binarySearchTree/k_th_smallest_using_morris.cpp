// #include <bits/stdc++.h> 
// /*************************************************************
 
//     Following is the Binary Tree node structure

//     class BinaryTreeNode 
//     {
//     public : 
//         T data;
//         BinaryTreeNode<T> *left;
//         BinaryTreeNode<T> *right;

//         BinaryTreeNode(T data) {
//             this -> data = data;
//             left = NULL;
//             right = NULL;
//         }
//     };

// *************************************************************/
// void MorrisTraversal( BinaryTreeNode<int>* root, int k, int& count, int& kthSmallest) {
//      BinaryTreeNode<int>* current = root;
//     while (current != NULL) {
//         if (current->left == NULL) {
//             count++;
//             if (count == k) {
//                 kthSmallest = current->data;
//                 return;
//             }
//             current = current->right;
//         } else {
//             BinaryTreeNode<int>* pre = current->left;
//             while (pre->right != NULL && pre->right != current)
//                 pre = pre->right;

//             if (pre->right == NULL) {
//                 pre->right = current;
//                 current = current->left;
//             } else {
//                 pre->right = NULL;
//                 count++;
//                 if (count == k) {
//                     kthSmallest = current->data;
//                     return;
//                 }
//                 current = current->right;
//             }
//         }
//     }
// }
// int kthSmallest(BinaryTreeNode<int>* root, int k) {
//     int count=0;
//     int kthSmallest=-1;
//     MorrisTraversal(root, k, count, kthSmallest);
//     return kthSmallest;
// }