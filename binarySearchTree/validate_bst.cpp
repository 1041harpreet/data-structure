// #include <bits/stdc++.h> 

 
//     // Following is the Binary Tree node structure

//     class BinaryTreeNode 
//     {
//     public : 
//         int data;
//         BinaryTreeNode<int> *left;
//         BinaryTreeNode<int> *right;

//         BinaryTreeNode(int data) {
//             this -> data = data;
//             left = NULL;
//             right = NULL;
//         }
//     };

// bool isBst(BinaryTreeNode<int> *root,int min,int max){
//     if(root==NULL){
//         return true;
//     }
//     if(root->data > min && root->data<max){
//         bool left=isBst(root->left,min,root->data);
//         bool right=isBst(root->right,root->data,max);
//         return left && right;
//     }else{
//         return false;
//     }
// }
// bool validateBST(BinaryTreeNode<int> *root) {
//     return isBst(root,INT_MIN,INT_MAX);
// }