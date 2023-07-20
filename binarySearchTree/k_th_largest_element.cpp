// #include <bits/stdc++.h> 
// /************************************************************
//     Following is the Binary Search Tree node structure
    
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
// int solve(TreeNode<int>* root, int k, int &count){
//     if(root==NULL){
//         return -1;
//     }
//     int right=solve(root->right, k, count);
//     if(right!=-1){
//         return right;
//     }
//     count++;
//     if(count==k){
//         return root->data;
//     }
//     return solve(root->left,  k, count);

// }
// int KthLargestNumber(TreeNode<int>* root, int k) 
// {
//      int count=0;
//     int ans=solve(root, k,count);
//     return ans;
// }
