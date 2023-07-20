// #include <bits/stdc++.h> 
// // Following is the Binary Tree node structure
// /**************
// class BinaryTreeNode {
//     public : 
//     T data;
//     BinaryTreeNode<T> *left;
//     BinaryTreeNode<T> *right;

//     BinaryTreeNode(T data) {
//         this -> data = data;
//         left = NULL;
//         right = NULL;
//     }
    
// };
// ***************/
// void storeValues(BinaryTreeNode<int>* root,vector<int>& vec){
//     if(root==NULL){
//         return;
//     }
//     storeValues(root->left,vec);
//     vec.push_back(root->data);
//     storeValues(root->right,vec);
// }
// bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
// 	vector<int> vec;
//     storeValues(root, vec);
//     int i=0;
//     int j=vec.size()-1;
//     while(i<j){
//         int sum=vec[i]+vec[j];
//         if(sum==target){
//             return true;
//         }
//         else if(sum > target){
//             j--;
//         }else{
//             i++;
//         }
//     }
//     return false;

// }