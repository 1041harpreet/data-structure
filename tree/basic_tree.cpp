// basic tree creation
#include <iostream>
using namespace std;
struct Node
{
  int data;
  struct Node *left;
  struct Node *right;
};
void inorder(Node *root)
{

  if (root == NULL)
  {
    return;
  }
  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}
void preorder(Node *root)
{
  
  if (root != NULL)
  {
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
  }
}
void postorder(Node *root)
{
  
  if (root != NULL)
  {
    
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
  }
}
int main()
{
  struct Node *head;
  struct Node *second;
  struct Node *third;
  struct Node *fourth;
  struct Node *fifth;
  struct Node *sixth;
  struct Node *seventh;
  // allocate 3 nodes in the heap
  head = (struct Node *)malloc(sizeof(struct Node));
  second = (struct Node *)malloc(sizeof(struct Node));
  third = (struct Node *)malloc(sizeof(struct Node));
  fourth = (struct Node *)malloc(sizeof(struct Node));
  fifth = (struct Node *)malloc(sizeof(struct Node));
  sixth = (struct Node *)malloc(sizeof(struct Node));
  seventh = (struct Node *)malloc(sizeof(struct Node));
  head->data = 10;     // assign data in first node
  head->left = second; // Link first node with second
  head->right = third;
  second->data = 5;
  third->data = 15;      // assign data in first node
  second->left = fourth; // Link first node with second
  second->right = fifth;
  third->left = sixth; // Link first node with second
  third->right = seventh;
  fourth->data = 2;
  fifth->data = 7;
  sixth->data = 12;
  seventh->data = 18;
  fourth->left = NULL;
  fourth->right = NULL;
  fifth->left = NULL;
  fifth->right = NULL;
  sixth->left = NULL;
  sixth->right = NULL;
  seventh->left = NULL;
  seventh->right = NULL;
  postorder(head);
  return 0;
}