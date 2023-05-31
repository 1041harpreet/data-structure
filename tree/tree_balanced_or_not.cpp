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

int height(Node *node);

bool treeBalancedOrNot(Node *root)
{
    if (root == NULL)
    {
        return true;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    if (abs(leftHeight - rightHeight) <= 1 && treeBalancedOrNot(root->left) && treeBalancedOrNot(root->right))
    {
        return 1;
    }
    return false;
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
    return 0;
}
