#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
 
    return (temp);
}

int height(Node *node);

bool isIsomorphic(Node *root1, Node *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    if (root1 == NULL || root2 == NULL)
    {
        return false;
    }
    if (root1->data != root2->data)
    {
        return false;
    }
    return (isIsomorphic(root1->left, root2->left) && isIsomorphic(root1->right, root2->right) || isIsomorphic(root1->left, root2->right) && isIsomorphic(root1->right, root2->left));
}
int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    if (left > right)
    {
        return left + 1;
    }
    else
    {
        return right + 1;
    }
}
int main()
{
   struct Node *n1 = newNode(1);
    n1->left        = newNode(2);
    n1->right       = newNode(3);
    // n1->left->left  = newNode(4);
    // n1->left->right = newNode(5);
    // n1->right->left  = newNode(6);
    // n1->left->right->left = newNode(7);
    // n1->left->right->right = newNode(8);
 
    struct Node *n2 = newNode(1);
    n2->left         = newNode(3);
    n2->right        = newNode(2);
    // n2->right->left   = newNode(4);
    // n2->right->right   = newNode(5);
    // n2->left->right   = newNode(6);
    // n2->right->right->left = newNode(8);
    // n2->right->right->right = newNode(7);
 
    if (isIsomorphic(n1, n2) == true)
       cout << "Yes";
    else
      cout << "No";
    return 0;
}
