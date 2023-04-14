// The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root .
#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
Node *newNode(int data)
{
    Node *node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
void mirror(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        Node *temp = new Node;
        mirror(root->left);
        mirror(root->right);
        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
   
    
}
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
int main()
{
    struct Node *head;
    // allocate 3 nodes in the heap
    head = (struct Node *)malloc(sizeof(struct Node));

    head = newNode(1);
    head->left = newNode(2);
    head->right = newNode(3);
    head->left->left = newNode(4);
    head->left->right = newNode(5);
    head->right->left = newNode(6);
    head->right->right = newNode(7);
    inorder(head);
    cout<<endl;
    mirror(head);
    cout<<endl;
    inorder(head);
    return 0;
}
