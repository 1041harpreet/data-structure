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
void levelOrderTraversal(Node *root)
{
    if(root==NULL)
    {return;}
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }
}
Node *insertIntoTree(Node *root, int data)
{
    if (root == NULL)
    {
        // create a new node
        root = new Node(data);
        return root;
    }
    else if (data <= root -> data){
        /* recur for the left subtree */
        root -> left = insertIntoTree(root -> left, data);
    }
    else{
        /* recur for the right subtree */
        root -> right = insertIntoTree(root -> right, data);
    }
    return root;
}
void takeInput(Node * &root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        root = insertIntoTree(root, data);
        cin >> data;
    }
}
int main()
{
    Node* root=NULL;
    cout<<"Enter elements of tree in level order: "<<endl;
    takeInput(root);
    levelOrderTraversal(root);
    return 0;
}