#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
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
Node *insertIntoTree(Node *root, int data)
{
    if (root == NULL)
    {
        // create a new node
        root = new Node(data);
        return root;
    }
    else if (data <= root->data)
    {
        /* recur for the left subtree */
        root->left = insertIntoTree(root->left, data);
    }
    else
    {
        /* recur for the right subtree */
        root->right = insertIntoTree(root->right, data);
    }
    return root;
}
void takeInput(Node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        root = insertIntoTree(root, data);
        cin >> data;
    }
}
int minValue(Node *root)
{
    Node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp->data;
}
Node *deleteNode(Node *root, int k)
{
    if (root == NULL)
    {
        return root;
    }
    if (root->data == k)
    {
        // 0 child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        // for 2 child
        if (root->left != NULL && root->right != NULL)
        {
            int min = minValue(root->right);
            root->data = min;
            root->right = deleteNode(root->right, min);
            return root;
        }
    }
    if (root->data > k)
    {
        root->left = deleteNode(root->left, k);
        return root;
    }
    else
    {
        root->right = deleteNode(root->right, k);
        return root;
    }
    return root;
}
int main()
{
    Node *root = NULL;
    cout << "Enter elements of tree in level order: " << endl;
    takeInput(root);
    inorder(root);
    root=deleteNode(root, 15);
    cout<<endl;
    inorder(root);
    return 0;
}