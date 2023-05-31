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

void topViewTraversal(Node *root)
{
    if(root==NULL){
        return ;
    }else{
        
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
   
    return 0;
}
