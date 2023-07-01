#include <iostream>
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

Node *getMid(Node *head)
{
    Node *slow_ptr = head;
    Node *fast_ptr = head->next;

    while (fast_ptr != NULL && fast_ptr->next != NULL)
    {
        fast_ptr = fast_ptr->next->next;
        slow_ptr = slow_ptr->next;
    }

    return slow_ptr;
}
Node *merge(Node *left, Node *right)
{
    if (left == NULL)
    {
        return right;
    }
    if (right == NULL)
    {
        return left;
    }
    Node *dummyHead = new Node(-1); // dummy Head to store merged Linked List
    Node *curr = dummyHead;         // curr is used as a pointer for traversing through both
    while ((left != NULL) && (right != NULL))
    {
        if (left->data < right->data)
        {
            curr->next = left;
            curr = left;
            left = left->next;
        }
        else
        {
            curr->next = right;
            curr = right;
            right = right->next;
        }
    }
    while (left != NULL)
    {

        curr->next = left;
        curr = left;
        left = left->next;
    }
    while (right != NULL)
    {

        curr->next = right;
        curr = right;
        right = right->next;
    }
    return dummyHead->next;
}
Node *mergeSort(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    // divide the linked list into two half
    Node *mid = getMid(head);
    Node *left = head;
    Node *right = mid->next;
    mid->next = NULL;
    left = mergeSort(left);

    right = mergeSort(right);
    Node *result = merge(left, right);
    return result;
}
int main()
{
    Node *head = new Node(60);
    insertAtEnd(head, 150);
    insertAtEnd(head, 10);
    insertAtEnd(head, 40);
    insertAtEnd(head, 35);
    insertAtEnd(head, 50);
    cout << endl;
    Node *n = mergeSort(head);
    print(n);
    return 0;
}