// TreeNode<int>* inOrderToBst(vector<int> &v,int s,int e){
//     if(s>e){
//         return NULL;
//     }
//     int mid=(s+e)/2;
//     TreeNode<int>* root=new TreeNode<int>(v[mid]);
//     root->left=inOrderToBst(v,s,mid-1);
//     root->right=inOrderToBst(v, mid+1,e);
//     return root;
// }