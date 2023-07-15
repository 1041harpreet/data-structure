#include <iostream>
#include <queue>
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
void inorder(Node *root, int &count)
{

    if (root == NULL)
    {
        return;
    }
    inorder(root->left, count);
    if (root->left == NULL && root->right == NULL)
    {
        count++;
    }
    inorder(root->right, count);
}
int leafNodeCount(Node *root)
{
    int count = 0;
    inorder(root, count);
    return count;
}
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
int main()
{
    Node *root = NULL;
    root = buildTree(root);
    cout<<" count is : "<<leafNodeCount(root);
    return 0;
}