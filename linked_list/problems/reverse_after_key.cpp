//Reverse a Linked List in groups of given size.
// A simple C program for
// traversal of a linked list

#include <iostream>
using namespace std;

struct Node {
	int data;
	struct Node* next;
};

// This function prints contents of linked list starting
// from the given node
void printList(struct Node* n)
{
	while (n != NULL) {
    cout<<n->data<<endl;	
	n = n->next;
	}
}

Node* reverse(struct Node* head,int key){
    Node* current=head;
    Node* prev=NULL;
    Node* next=NULL;
	int i=0;
    while (current !=NULL &  i< key)
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
		i++;
	}
	if (head !=NULL)
	{
		head->next=reverse(next,key);
	}
	
	return prev;
}
// Driver's code
int main()
{
	struct Node* head;
	struct Node* second;
	struct Node* third;
    struct Node* fourth;
    struct Node* fifth;
    struct Node* sixth;
	// allocate 3 nodes in the heap
	head = (struct Node*)malloc(sizeof(struct Node));
	second = (struct Node*)malloc(sizeof(struct Node));
	third = (struct Node*)malloc(sizeof(struct Node));
	fourth = (struct Node*)malloc(sizeof(struct Node));
	fifth = (struct Node*)malloc(sizeof(struct Node));
	sixth = (struct Node*)malloc(sizeof(struct Node));


	head->data = 1; // assign data in first node
	head->next = second; // Link first node with second

	second->data = 2; // assign data to second node
	second->next = third;

	third->data = 3; 
	third->next = fourth;
    fourth->data = 4; 
	fourth->next = fifth;
	fifth->data = 5; 
	fifth->next = sixth;
	sixth->data = 6; 
	sixth->next = NULL;
	// Function call
	printList(head);
	head=reverse(head,2);
	cout<<"after reverse"<<endl;
	printList(head);
	return 0;
}
