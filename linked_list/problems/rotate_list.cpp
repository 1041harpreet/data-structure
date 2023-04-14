// A simple C program for
// traversal of a linked list

#include<iostream>
using namespace std;

struct node {
	int data;
	struct node* next;
};

// This function prints contents of linked list starting
// from the given node
void printList(struct node* n)
{
	while (n != NULL) {
        cout<<n->data<<endl;
		n = n->next;
	}
}

void rotateList(struct node* head, int k ){
    node* temp=head;
    for (int i = 0; i < k; i++)
    {
        temp=temp->next;
    }
    cout<<"temp is "<<temp->data<<endl;
    while (head != NULL)
    {
        head=head->next;
    }
    cout<<"head is"<<head<<endl;
    
    // change k node to null
    //change k+1 node to head

    
}

// Driver's code
int main()
{
	struct node* head;
	struct node* second;
	struct node* third;

	// allocate 3 nodes in the heap
	head = (struct node*)malloc(sizeof(struct node));
	second = (struct node*)malloc(sizeof(struct node));
	third = (struct node*)malloc(sizeof(struct node));

	head->data = 1; // assign data in first node
	head->next = second; // Link first node with second

	second->data = 2; // assign data to second node
	second->next = third;

	third->data = 3; // assign data to third node
	third->next = NULL;

	// Function call
	printList(head);
    cout<<"Rotate List"<<endl;
    rotateList(head,2);

	return 0;
}
