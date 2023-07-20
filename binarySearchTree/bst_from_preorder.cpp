//first we did using construct tree that we did in 
// Node *buildTree(Node *root)
// {
//     cout << "enter data for node " << endl;
//     int data;
//     cin >> data;
//     root = new Node(data);

//     if (data == -1)
//     {
//         return NULL;
//     }
//     cout << "enter for left of " << data << endl;
//     root->left = buildTree(root->left);
//     cout << "enter for right of " << data << endl;
//     root->right = buildTree(root->right);
//     return root;
// }

//2 sort preorder into inorder and make a treee from pre+inorder 
//but tc. O(nlogn)

//3 
// #include <bits/stdc++.h>
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/
// TreeNode<int> *solve(vector<int> &preOrder, int min, int max, int &i) {
//   if (i >= preOrder.size() || preOrder[i] < min || preOrder[i] > max) {
//     return NULL;
//   }
//   TreeNode<int> *root = new TreeNode<int>(preOrder[i++]);
//   root->left = solve(preOrder, min, root->data, i);
//   root->right = solve(preOrder, root->data, max, i);
//   return root;
// }
// TreeNode<int> *preOrderTree(vector<int> &preOrder) {
//   int mini = INT_MIN;
//   int maxi = INT_MAX;
//   int i = 0;
//   return solve(preOrder, mini, maxi, i);
// }
