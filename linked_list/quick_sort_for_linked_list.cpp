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




int main()
{
    Node *head = new Node(60);
    insertAtEnd(head, 150);
    insertAtEnd(head, 10);
    insertAtEnd(head, 40);
    insertAtEnd(head, 35);
    insertAtEnd(head, 50);
    cout << endl;
    // Node *n = quickSort(head);
    // print(n);
    return 0;
}