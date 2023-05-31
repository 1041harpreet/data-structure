// C++ program to print left view of
// Binary Tree

#include<bits/stdc++.h>
using namespace std;

// A Binary Tree Node
struct Node
{
	int data;
	struct Node *left, *right;
};

// Utility function to create a new tree node
Node* newNode(int data)
{
	Node *temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

// function to print left view of
// binary tree
void printrightView(Node* root)
{
	if (!root)
		return;

	queue<Node*> q;
	q.push(root);

	while (!q.empty())
	{	
		// number of nodes at current level
		int n = q.size();
		
		// Traverse all nodes of current level
		while(n--)
		{
			Node* temp = q.front();
			q.pop();
				
			// Print the left most element
			// at the level
			if (n == 0)
				cout<<temp->data<<" ";
			
			// Add left node to queue
			if (temp->left != NULL)
				q.push(temp->left);

			// Add right node to queue
			if (temp->right != NULL)
				q.push(temp->right);
		}
	}
}	

// Driver code
int main()
{
	// Let's construct the tree as
	// shown in example

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
	printrightView(head);
}
