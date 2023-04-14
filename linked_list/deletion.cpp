// A simple C program for
// traversal of a linked list

#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};
// deletion at first
struct Node* deleteAtFirst(struct Node* head){
        head=head->next;
    return head;
}
//delete at last
void deleteAtLast(struct Node * head){
    struct Node* ptr,* ptr1;
    ptr=head;
    while (ptr->next !=NULL)
    {
     ptr1=ptr;
     ptr=ptr->next;   
    }
    ptr1->next=NULL;
    free(ptr);
}
//delete random
void deleteAtRandom(struct Node* head,int num){
    struct Node* ptr,*ptr1;
    ptr=head;
    for (int i = 0; i < num; i++)
    {
        ptr1=ptr;
       ptr=ptr->next;
    }
    ptr1->next=ptr->next;
    free(ptr);
    
    
}
// This function prints contents of linked list starting
// from the given node
void printList(struct Node *n)
{
    while (n != NULL)
    {
       cout<<n->data<<endl;
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
    //delete at first
    // Node * newNode=deleteAtFirst(head);
    //delete at last
    
    cout<<"After Delete"<<endl;
    // deleteAtLast(head);
    deleteAtRandom(head,2);
    printList(head);
    return 0;
}
