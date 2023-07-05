// // CPP program to segregate even and odd nodes in a
// // Linked List
// #include <bits/stdc++.h>
// using namespace std;

// /* a node of the singly linked list */
// struct Node {
// 	int data;
// 	struct Node* next;
// };

// // Function to segregate even and odd nodes.
// void segregateEvenOdd(struct Node** head_ref)
// {
// 	// Starting node of list having even values.
// 	Node* evenStart = NULL;
// 	// Ending node of even values list.
// 	Node* evenEnd = NULL;
// 	// Starting node of odd values list.
// 	Node* oddStart = NULL;
// 	// Ending node of odd values list.
// 	Node* oddEnd = NULL;
// 	// Node to traverse the list.
// 	Node* currNode = *head_ref;

// 	while (currNode != NULL) {
// 		int val = currNode->data;

// 		// If current value is even, add it to even values
// 		// list.
// 		if (val % 2 == 0) {
// 			if (evenStart == NULL) {
// 				evenStart = currNode;
// 				evenEnd = evenStart;
// 			}
// 			else {
// 				evenEnd->next = currNode;
// 				evenEnd = evenEnd->next;
// 			}
// 		}

// 		// If current value is odd, add it to odd values
// 		// list.
// 		else {
// 			if (oddStart == NULL) {
// 				oddStart = currNode;
// 				oddEnd = oddStart;
// 			}
// 			else {
// 				oddEnd->next = currNode;
// 				oddEnd = oddEnd->next;
// 			}
// 		}

// 		// Move head pointer one step in forward direction
// 		currNode = currNode->next;
// 	}

// 	// If either odd list or even list is empty, no change
// 	// is required as all elements are either even or odd.
// 	if (oddStart == NULL || evenStart == NULL)
// 		return;

// 	// Add odd list after even list.
// 	evenEnd->next = oddStart;
// 	oddEnd->next = NULL;

// 	// Modify head pointer to starting of even list.
// 	*head_ref = evenStart;
// }

// /* UTILITY FUNCTIONS */
// /* Function to insert a node at the beginning */
// void push(Node** head_ref, int new_data)
// {
// 	/* allocate node */
// 	Node* new_node = new Node();
// 	/* put in the data */
// 	new_node->data = new_data;
// 	/* link the old list of the new node */
// 	new_node->next = (*head_ref);
// 	/* move the head to point to the new node */
// 	(*head_ref) = new_node;
// }

// /* Function to print nodes in a given linked list */
// void printList(Node* node)
// {
// 	while (node != NULL) {
// 		cout << node->data << " ";
// 		node = node->next;
// 	}
// }

// /* Driver program to test above functions*/
// int main()
// {
// 	/* Start with the empty list */
// 	Node* head = NULL;

// 	/* Let us create a sample linked list as following
// 	0->1->4->6->9->10->11 */

// 	push(&head, 11);
// 	push(&head, 10);
// 	push(&head, 9);
// 	push(&head, 6);
// 	push(&head, 4);
// 	push(&head, 1);
// 	push(&head, 0);

// 	cout << "Original Linked list" << endl;
// 	printList(head);

// 	segregateEvenOdd(&head);

// 	cout << endl << "Modified Linked list " << endl;
// 	printList(head);

// 	return 0;
// }

// Method 1
// The idea is to get a pointer to the last node of list. And then traverse the list starting from the head node and move the odd valued nodes from their current position to end of the list.

// Follow the steps below to implement the above idea:

// Get a pointer to the last node.
// Move all the odd nodes to the end.
// Consider all odd nodes before the first even node and move them to end.
// Change the head pointer to point to the first even node.
//  Consider all odd nodes after the first even node and move them to the end.
#include <iostream>
#include <map>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
void insertAtEnd(Node *head, int data)
{
    Node *node = new Node(data);
    while (head->next != NULL)
    {
        head = head->next;
    }
    head->next = node;
}

Node *segregateNode(Node *head)
{
    // get last node and add element to last
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *last = head;
    Node *temp = head;
    Node *pre = NULL;
    while (temp != NULL)
    {

        pre = temp;
        temp = temp->next;
    }

    last = pre;
    // cout << last->data;
    /* Move all odd nodes after last */
    temp = head;
    while (temp != NULL)
    {
        if(temp->data%2 !=0 && temp !=last){
            int data=temp->data ;
            last->next=temp;
            temp=temp->next;

        }
    }

    return head;
}
int main()
{

    Node *head = new Node(1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 4);
    insertAtEnd(head, 5);
    insertAtEnd(head, 6);
    segregateNode(head);
    return 0;
}