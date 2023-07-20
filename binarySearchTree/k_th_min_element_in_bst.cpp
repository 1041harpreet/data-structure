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
// int solve(BinaryTreeNode<int>* root, int k, int &count){
//     if(root==NULL){
//         return -1;
//     }
//     int left=solve(root->left, k, count);
//     if(left!=-1){
//         return left;
//     }
//     count++;
//     if(count==k){
//         return root->data;
//     }
//     return solve(root->right,  k, count);

// }
// int kthSmallest(BinaryTreeNode<int>* root, int k) {
//     int count=0;
//     int ans=solve(root, k,count);
//     return ans;
// }