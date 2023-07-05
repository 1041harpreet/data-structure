// #include <iostream>
// using namespace std;
// class Node
// {
// public:
//     int data;
//     Node *next;

//     Node(int data)
//     {
//         this->data = data;
//         next = NULL;
//     }
// };
// void print(Node *head)
// {
//     while (head != NULL)
//     {
//         cout << head->data << " ";
//         head = head->next;
//     }
// }

// void insertAtEnd(Node *head, int data)
// {
//     Node *node = new Node(data);
//     while (head->next != NULL)
//     {
//         head = head->next;
//     }
//     head->next = node;
// }

// Node *reverseLinkedList(Node *head)
// {
//     if (head == NULL || head->next == NULL)
//     {
//         return head;
//     }
//     Node *newhead = reverseLinkedList(head->next);
//     head->next->next = head;
//     head->next = NULL;
//     return newhead;
// }

// Node *ans(Node *head)
// {
//     // res is head node of the resultant list
//     Node *res = head;
//     Node *temp;

//     int carry = 1, sum;

//     while (head != NULL) // while both lists exist
//     {
//         // Calculate value of next digit in resultant list.
//         // The next digit is sum of following things
//         // (i) Carry
//         // (ii) Next digit of head list (if there is a
//         // next digit)
//         sum = carry + head->data;

//         // update carry for next calculation
//         carry = (sum >= 10) ? 1 : 0;

//         // update sum if it is greater than 10
//         sum = sum % 10;

//         // Create a new node with sum as data
//         head->data = sum;

//         // Move head and second pointers to next nodes
//         temp = head;
//         head = head->next;
//     }

//     // if some carry is still there, add a new node to
//     // result list.
//     if (carry > 0)
//     {
//         Node *n = new Node(carry);
//         temp->next = n;
//     }
//     return res;
// }
// Node *addOne(Node *head)
// {
//     // 1->2->3->null to 124 as node*
//     Node *newNode = reverseLinkedList(head);
//     head = ans(newNode);
//     return reverseLinkedList(head);
// }
// int main()
// {
//     Node *head = new Node(1);
//     insertAtEnd(head, 2);
//     insertAtEnd(head, 3);
//     cout << endl;
//     print(head);
//     cout << endl;
//     addOne(head);
//     cout << endl;

//     return 0;
// }

// C++ program to add 1 to a linked list
#include <bits/stdc++.h>
using namespace std;

/* Linked list node */
class Node
{
	public:
	int data;
	Node* next;
};

/* Function to create a new node with given data */
Node *newNode(int data)
{
	Node *new_node = new Node;
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

/* Function to reverse the linked list */
Node *reverse(Node *head)
{
	Node * prev = NULL;
	Node * current = head;
	Node * next;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	return prev;
}

/* Adds one to a linked lists and return the head
node of resultant list */
Node *addOneUtil(Node *head)
{
	// res is head node of the resultant list
	Node* res = head;
	Node *temp;

	int carry = 1, sum;

	while (head != NULL) //while both lists exist
	{
		// Calculate value of next digit in resultant list.
		// The next digit is sum of following things
		// (i) Carry
		// (ii) Next digit of head list (if there is a
		// next digit)
		sum = carry + head->data;

		// update carry for next calculation
		carry = (sum >= 10)? 1 : 0;

		// update sum if it is greater than 10
		sum = sum % 10;

		// Create a new node with sum as data
		head->data = sum;

		// Move head and second pointers to next nodes
		temp = head;
		head = head->next;
	}

	// if some carry is still there, add a new node to
	// result list.
	if (carry > 0)
		temp->next = newNode(carry);

	// return head of the resultant list
	return res;
}

// This function mainly uses addOneUtil().
Node* addOne(Node *head)
{
	// Reverse linked list
	head = reverse(head);

	// Add one from left to right of reversed
	// list
	head = addOneUtil(head);

	// Reverse the modified list
	return reverse(head);
}

// A utility function to print a linked list
void printList(Node *node)
{
	while (node != NULL)
	{
		cout << node->data;
		node = node->next;
	}
	cout<<endl;
}

/* Driver program to test above function */
int main(void)
{
	Node *head = newNode(1);
	head->next = newNode(9);
	head->next->next = newNode(9);
	head->next->next->next = newNode(9);

	cout << "List is ";
	printList(head);

	head = addOne(head);

	cout << "\nResultant list is ";
	printList(head);

	return 0;
}

// This is code is contributed by rathbhupendra
