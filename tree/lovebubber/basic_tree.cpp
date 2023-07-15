#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
Node *buildTree(Node *root)
{
    cout << "enter data for node " << endl;
    int data;
    cin >> data;
    root = new Node(data);

    if (data == -1)
    {
        return NULL;
    }
    cout << "enter for left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "enter for right of " << data << endl;
    root->right = buildTree(root->right);
    return root;
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
    Node *root = NULL;
    root = buildTree(root);
    return 0;
}