#include <stack>
#include <iostream>
#include <queue>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

void reverseLevelOrder(Node *root)
{
    queue<Node *> q;
    stack<Node *> s;

    q.push(root);
    // q.push(NULL);
    while (!q.empty())
    {
        root = q.front();
        q.pop();
        s.push(root);

        if (root->right)
        {
            q.push(root->right);
        }
        if (root->left)
        {
            q.push(root->left);
        }
    }
    while (!s.empty())
    {
        root = s.top();
        cout << root->data << " ";
        s.pop();
    }
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fifth;
    struct Node *sixth;
    struct Node *seventh;
    // allocate 3 nodes in the heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    fifth = (struct Node *)malloc(sizeof(struct Node));
    sixth = (struct Node *)malloc(sizeof(struct Node));
    seventh = (struct Node *)malloc(sizeof(struct Node));
    head->data = 10;     // assign data in first node
    head->left = second; // Link first node with second
    head->right = third;
    second->data = 5;
    third->data = 15;      // assign data in first node
    second->left = fourth; // Link first node with second
    second->right = fifth;
    third->left = sixth; // Link first node with second
    third->right = seventh;
    fourth->data = 2;
    fifth->data = 7;
    sixth->data = 12;
    seventh->data = 18;
    fourth->left = NULL;
    fourth->right = NULL;
    fifth->left = NULL;
    fifth->right = NULL;
    sixth->left = NULL;
    sixth->right = NULL;
    seventh->left = NULL;
    seventh->right = NULL;
    reverseLevelOrder(head);
    return 0;
}