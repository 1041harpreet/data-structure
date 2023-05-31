// // C++ program to print left view of
// // Binary Tree

// #include<bits/stdc++.h>
// using namespace std;

// // A Binary Tree Node
// struct Node
// {
// 	int data;
// 	struct Node *left, *right;
// };

// // Utility function to create a new tree node
// Node* newNode(int data)
// {
// 	Node *temp = new Node;
// 	temp->data = data;
// 	temp->left = temp->right = NULL;
// 	return temp;
// }

// // function to print left view of
// // binary tree
// void printLeftView(Node* root)
// {
// 	if (!root)
// 		return;

// 	queue<Node*> q;
// 	q.push(root);

// 	while (!q.empty())
// 	{	
// 		// number of nodes at current level
// 		int n = q.size();
		
// 		// Traverse all nodes of current level
// 		for(int i = 1; i <= n; i++)
// 		{
// 			Node* temp = q.front();
// 			q.pop();
				
// 			// Print the left most element
// 			// at the level
// 			if (i == 1)
// 				cout<<temp->data<<" ";
			
// 			// Add left node to queue
// 			if (temp->left != NULL)
// 				q.push(temp->left);

// 			// Add right node to queue
// 			if (temp->right != NULL)
// 				q.push(temp->right);
// 		}
// 	}
// }	

// // Driver code
// int main()
// {
// 	// Let's construct the tree as
// 	// shown in example

// 	Node* root = newNode(10);
// 	root->left = newNode(2);
// 	root->right = newNode(3);
// 	root->left->left = newNode(7);
// 	root->left->right = newNode(8);
// 	root->right->right = newNode(15);
// 	root->right->left = newNode(12);
// 	root->right->right->left = newNode(14);

// 	printLeftView(root);
// }




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
void leftViewFun(Node*root, int level,int* maxLevel){
    if(root == NULL){
        return;
    }else{
        if(level > *maxLevel){
            cout<<root->data<<" ";
            *maxLevel = level;

        }
        leftViewFun(root->left,level+1,maxLevel);
        leftViewFun(root->right,level+1,maxLevel);
    }
}
void leftView(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        int maxLevel=0;
        leftViewFun(root,1,&maxLevel);
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
    // head->left->left = newNode(4);
    head->left->right = newNode(5);
    head->right->left = newNode(6);
    head->right->right = newNode(7);
    head->right->left->left = newNode(8);
    leftView(head);
    return 0;
}
