// #include <bits/stdc++.h>
// /*************************************************************

//     Following is the Binary Tree node structure:

//     class TreeNode{

//         public :
//             int data;
//             TreeNode *left;
//             TreeNode *right;

//             TreeNode(int data) {
//                 this -> data = data;
//                 left = NULL;
//                 right = NULL;
//             }

//             ~TreeNode() {
//             if (left){
//             delete left;
//             }

//             if (right){
//             delete right;
//             }
//         }
//     };

// *************************************************************/
// void storeInorder(TreeNode<int> *root, vector<int> &v) {
//   if (root == NULL) {
//     return ;
//   }
//   storeInorder(root->left, v);
//   v.push_back(root->data);
//   storeInorder(root->right, v);
// }
// TreeNode<int> *inOrderToBst(vector<int> &v, int s, int e) {
//   if (s > e) {
//     return NULL;
//   }
//   int mid = (s + e) / 2;
//   TreeNode<int> *root = new TreeNode<int>(v[mid]);
//   root->left = inOrderToBst(v, s, mid - 1);
//   root->right = inOrderToBst(v, mid + 1, e);
//   return root;
// }
// vector<int> mergeArray(vector<int> v1, vector<int> v2) {
//   vector<int> v(v1.size() + v2.size());
//   int i = 0;
//   int j = 0;
//   int k = 0;
//   while (i < v1.size() && j < v2.size()) {
//     if (v1[i] > v2[j]) {
//       v[k++] = v2[j];
//       j++;
//     } else {
//       v[k++] = v1[i];
//       i++;
//     }
//   }
//   while (i < v1.size()) {
//     v[k++] = v1[i];
//     i++;
//   }
//   while (j < v2.size()) {
//     v[k++] = v2[j];
//     j++;
//   }
//   return v;
// }
// TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2) {
//   vector<int> v1, v2;
//   // store both into vectors
//   storeInorder(root1, v1);
//   storeInorder(root2, v2);
//   // merge both vectors
//   vector<int> v = mergeArray(v1, v2);
//   // inorder of merge
//   return inOrderToBst(v, 0, v.size() - 1);
// }

//above solution s.c is O(m+n)
//so we need to find solution in O(h1+h2)
// time complexity where h1 and h2 are heights of two trees respectively



// void convertToSortedDLL(TreeNode<int>* root, TreeNode<int>* &head) {

//     // base case
//     if(root == NULL)
//         return;
    
//     convertToSortedDLL(root->right, head);

//     root->right = head;

//     if(head != NULL) {
//         head->left = root;
//     }
//     head = root;
//     convertToSortedDLL(root->left, head);
// }


// TreeNode<int>* mergeLL(TreeNode<int>* head1, TreeNode<int>* head2) {

//     TreeNode<int>* head = NULL;
//     TreeNode<int>* tail = NULL;

//     while(head1 != NULL && head2 != NULL) {

//         if(head1->data < head2->data) {
//             if(head == NULL) {
//                 head = head1;
//                 tail = head1;
//                 head1 = head1->right;
//             }
//             else {
//                 tail->right = head1;
//                 head1->left = tail;
//                 tail = head1;
//                 head1 = head1->right;
//             }
//         }
//         else {
//             if(head == NULL) {
//                 head = head2;
//                 tail = head2;
//                 head2 = head2->right;
//             }
//             else {
//                 tail->right = head2;
//                 head2->left = tail;
//                 tail = head2;
//                 head2 = head2->right;
//             }
//         }
//     }

//     while(head1 != NULL) {
//         tail->right = head1;
//         head1->left = tail;
//         tail = head1;
//         head1 = head1->right;
//     }

//     while(head2 != NULL) {
//         tail->right = head2;
//         head2->left = tail;
//         tail = head2;
//         head2 = head2->right;
//     }
//     return head;
// }


// int countNodes(TreeNode<int>* head) {

//     int cnt = 0;
//     TreeNode<int>* temp = head;

//     while(temp != NULL) {
//         cnt++;
//         temp = temp->right;
//     }
//     return cnt;
// }


// TreeNode<int>* sortedLinkedListToBST(TreeNode<int>* &head, int n) {

//     // base case
//     if(n <= 0 || head == NULL) {
//         return NULL;
//     }

//     TreeNode<int>* left = sortedLinkedListToBST(head, n/2);

//     TreeNode<int>* root = head;
//     root->left = left;

//     head = head->right;

//     root->right = sortedLinkedListToBST(head, n - n/2 - 1);
//     return root;
// }


// TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2) {

//     // step 1: convert BST into sorted DLL in-place
//     TreeNode<int>* head1 = NULL;
//     convertToSortedDLL(root1, head1);
//     head1->left = NULL;

//     TreeNode<int>* head2 = NULL;
//     convertToSortedDLL(root2, head2);
//     head2->left = NULL; 

//     // step 2: merge sorted LL
//     TreeNode<int>* head = mergeLL(head1, head2);

//     // step 3: convert SLL to BST
//     return sortedLinkedListToBST(head, countNodes(head));
// }