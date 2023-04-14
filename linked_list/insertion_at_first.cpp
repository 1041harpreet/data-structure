// A simple C program for
// traversal of a linked list

#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};
// insert at first
void insertAtFirst(struct Node *head)
{

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = 5;
    newNode->next = head;
    head = newNode;
    cout << "head value is" << head->next->data;
}

// insert at end
void insertAtEnd(struct Node *head)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    while (head->next != NULL)
    {
        head = head->next;
    }
    head->next = newNode;
    newNode->data = 5;
    newNode->next = NULL;
}

// insertion at any point
void insertionAtRandom(struct Node *head, int num)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    for (int i = 0; i < num-1; i++)
    {
        head=head->next;
    }
    
    newNode->next = head->next;
    head->next = newNode;
    newNode->data = 5;
}
// This function prints contents of linked list starting
// from the given node
void printList(struct Node *n)
{
    while (n != NULL)
    {
        printf(" %d ", n->data);
        n = n->next;
    }
}

// Driver's code
int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;

    // allocate 3 nodes in the heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 1;      // assign data in first node
    head->next = second; // Link first node with second

    second->data = 2; // assign data to second node
    second->next = third;

    third->data = 3; // assign data to third node
    third->next = NULL;
    struct Node *temp = head;
    // Function call
    printList(head);
    // insertAtFirst(head);
    // insertAtEnd(temp);
    insertionAtRandom(temp,1);
    cout << endl;
    printList(head);

    return 0;
}
