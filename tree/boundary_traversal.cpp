// The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root .
#include <iostream>
#include <vector>
#include <queue>
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
void leftTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {

        if (root->left)
        {
            cout << root->data << " ";
            leftTraversal(root->left);
        }
        else if (root->right)
        {
            cout << root->data << " ";
            leftTraversal(root->right);
        }
    }
}
void rightTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {

        if (root->right)
        {
            cout << root->data << " ";
            rightTraversal(root->right);
        }
        else if (root->left)
        {
            cout << root->data << " ";
            rightTraversal(root->left);
        }
    }
}
void leafTraversal(Node* root){
    if (root == NULL){
        return;
    }else{
        leafTraversal(root->left);
        if(!(root->left)&& !(root->right)){
            cout << root->data << " ";
        }
        leafTraversal(root->right);
    }

}
void boundaryTraversal(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    else
    {
        cout << node->data << " ";
        leftTraversal(node->left);
        leafTraversal(node->left);
        leafTraversal(node->right);
        rightTraversal(node->right);
        
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
    head->left->right->left = newNode(8);
    boundaryTraversal(head);
    return 0;
}
