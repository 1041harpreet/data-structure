#include <iostream>
#include <queue>
#include <stack>
#include<bits/stdc++.h>
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

vector<int> reverseLevelOrder(Node *root){
    // Write your code here.
   queue<Node*> q;
    vector<int> v;
    if(root==NULL)
    {
        return v;
    }
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node *temp=q.front();
        q.pop();

        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else
        {
            v.push_back(temp->data);

            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }

        }
    }
    reverse(v.begin(),v.end());
    return v;
}
int main()
{
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    Node *root = NULL;
    root = buildTree(root);
    // ReverselevelOrderTraversal(root);
    return 0;
}