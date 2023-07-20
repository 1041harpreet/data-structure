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
    if (root == NULL)
    {
        return;
    }
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

//1 add to vector using inorder. and beofre key is pre and afterkey is successor
void inorderPreSuc(Node *root, Node* &pre,Node* &succ,int k)
{
    
    if (root == NULL)
    {
        return ;
    }
    if (root->data == k)
    {
         // the maximum value in left subtree is predecessor
        if (root->left != NULL)
        {
            Node* tmp = root->left;
            while (tmp->right)
                tmp = tmp->right;
            pre = tmp ;
        }
 
        // the minimum value in right subtree is successor
        if (root->right != NULL)
        {
            Node* tmp = root->right ;
            while (tmp->left)
                tmp = tmp->left ;
            succ = tmp ;
        }
        return ;   
    }
    else if (root->data > k)
    {
        succ=root;
        return inorderPreSuc(root->left, pre,succ,k);
    }
    else
    {
        pre=root;
        return inorderPreSuc(root->right,pre,succ,k);
    }
}
//second ans first use while loop until key is found , then move to left one and right until it is null.  same for succ ,first go to right and left until null and save ans before moving.
int main()
{
    Node *root = NULL;
    cout << "Enter elements of tree in level order: " << endl;
    takeInput(root);
    levelOrderTraversal(root);
    Node* suc=NULL;
    Node* pre=NULL;
    int key=10;
    inorderPreSuc(root,pre,suc,key);
    cout<<"The Predecessor and Successor for "<<key <<" are : "<<endl;
    if (pre != NULL)
      cout << "Predecessor is " << pre->data << endl;
    else
      cout << "No Predecessor";
 
    if (suc != NULL)
      cout << "Successor is " << suc->data;
    else
      cout << "No Successor";
    return 0;
}