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

Node *reverseLinkedList(Node *head, int k)
{
    if (head == NULL )
    {
        return NULL;
    }
    Node *curr = head;
    Node *prev = NULL;
    Node *next = NULL;
    int count = 0;
    while (curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if (next != NULL)
    {
        Node *newhead = reverseLinkedList(next, k);
        head->next = newhead;
    }

    return prev;

}
int main()
{
    Node *head = new Node(10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);
    insertAtEnd(head, 50);
    cout << endl;
    print(head);
    Node *v = reverseLinkedList(head, 2);
    cout << endl;
    print(v);

    return 0;
}