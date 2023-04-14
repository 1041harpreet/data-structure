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
int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
int height(Node *node);
int diameterOfTree(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        int leftheight = height(root->left);
        int rightheight = height(root->right);  
        int leftdiameter=diameterOfTree(root->left);
        int rightdiamter=diameterOfTree(root->right);

        // cout<<"left "<<leftheight<< " right "<<rightheight;
        int diameter=max(max(leftdiameter,rightdiamter),leftheight+rightheight+1);
        return diameter;
    }
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

    int diameter = diameterOfTree(head);
    cout << "diamter is " << diameter;
    return 0;
}
