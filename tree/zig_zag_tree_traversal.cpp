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
vector<int> zigZagTree(Node *root)
{
    vector<int> v;
    if (root == NULL)
    {
        return v;
    }
    else
    {
        queue<Node *> q;
        bool leftToRight = true;
        q.push(root);
        
        while (!q.empty())
        {
            int size = q.size();
            vector<int>ans(size);
           for (int i = 0; i < size; i++)
            {
                Node *node = q.front();
                q.pop();
                int index = leftToRight ? i : size - i - 1;
                ans[index] = node->data;
                if (node->left)
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                }

            }
            leftToRight=!leftToRight;
            for(auto i:ans){
                v.push_back(i);
            }
        }
        return v;
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
     head->left->left->left = newNode(4);
    head->left->left->right = newNode(5);
    head->right->right->left = newNode(6);
    head->right->right->right = newNode(7);
    vector<int> v=zigZagTree(head);
    for (auto i:v){
        cout<<i<<" ";
    }
    return 0;
}
