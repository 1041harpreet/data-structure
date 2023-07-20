// /*************************************************************
//     Following is the Binary Serach Tree node structure

//     template <typename T>
//     class TreeNode
//     {
//     public :
//         T data;
//         TreeNode<T> *left;
//         TreeNode<T> *right;

//         TreeNode(T data) {
//             this -> data = data;
//             left = NULL;
//             right = NULL;
//         }

//         ~TreeNode() {
//             if (left)
//                 delete left;
//             if (right)
//                 delete right;
//         }
//     };

// *************************************************************/
// void inorder(TreeNode<int> *root, vector<int> &vec) {
//   if (root == NULL) {
//     return;
//   }
//   inorder(root->left, vec);
//   vec.push_back(root->data);
//   inorder(root->right, vec);
// }
// TreeNode<int> *solution( int s, int e, vector<int>&vec) {
//   if (s > e) {
//     return NULL;
//   }
//   int mid = (s + e) / 2;
//   TreeNode<int> *root = new TreeNode<int>(vec[mid]);
//   root->left = solution( s, mid - 1, vec);
//   root->right = solution( mid + 1, e, vec);
//   return root;
// }
// TreeNode<int> *balancedBst(TreeNode<int> *root) {
//   // as inorder of bst and balanced is same , we store in vector
//   vector<int> v;
//   inorder(root, v);
//   return solution(0,v.size()-1, v);
// }
