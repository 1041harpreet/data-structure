#include <bits/stdc++.h> 
#include<iostream>

    // Following is the Binary Tree node structure:

    // class BinaryTreeNode {
    // public : 
    //     T data;
    //     BinaryTreeNode<T> *left;
    //     BinaryTreeNode<T> *right;

    //     BinaryTreeNode(T data) {
    //         this -> data = data;
    //         left = NULL;
    //         right = NULL;
    //     }
    // };

// bool searchInBSTiterative(BinaryTreeNode<int> *root, int x) {
//   BinaryTreeNode<int> *temp = root;
//   while (temp != NULL) {
//     if (temp->data == x) {
//       return true;
//     } else if (temp->data > x) {
//       temp=temp->left;
//     } else {
//       temp=temp->right;
//     }
//   }
//   return false;
// }
// bool searchInBST(BinaryTreeNode<int> *root, int x) {
//     if(root==NULL){
//         return false;
//     }
//     if(root->data==x){
//         return true;
//     }
//     else if(root->data > x){
//         return searchInBST(root->left, x);
//     }else{
//         return searchInBST(root->right,x);
//     }
//     return false;
// }