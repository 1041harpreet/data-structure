#include <iostream>
#include <vector>
#include <queue>
#include <map>
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

vector<int> verticalOrderTraversal(Node *root)
{
    vector<int> ans;
    // Node* is node, first int is horizental distance and second is level;
    queue<pair<Node *, pair<int, int>>> q;
    // hd , level and nodes
    map<int, map<int, vector<int>>> nodes;
    if (root == NULL)
    {
        return ans;
    }
    else
    {
        q.push(make_pair(root, make_pair(0, 0)));
        while (!q.empty())
        {
            pair<Node *, pair<int, int>> temp = q.front();
            q.pop();
            Node *firstNode = temp.first;
            int hd = temp.second.first;
            int level = temp.second.second;
            nodes[hd][level].push_back(firstNode->data);
            if (firstNode->left)
            {
                q.push(make_pair(firstNode->left, make_pair(hd - 1, level + 1)));
            }
            if (firstNode->right)
            {
                q.push(make_pair(firstNode->right, make_pair(hd + 1, level + 1)));
            }
        }
        for (auto i : nodes)
        {
            for (auto j : i.second)
            {
                for (auto k : j.second)
                {
                    ans.push_back(k);
                }
            }
        }
        return ans;
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
    vector<int> v=verticalOrderTraversal(head);
    for(auto i: v){
        cout<<i<<" ";
    }
    return 0;
}
