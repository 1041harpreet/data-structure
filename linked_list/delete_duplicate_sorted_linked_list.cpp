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

// remove duplicate
void removeDuplicate(Node *head)
{

    if (head == NULL)
    {
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        if ((temp->next != NULL) && temp->data == temp->next->data)
        {
            Node *next = temp->next->next;
            delete (temp->next);
            temp->next = next;
        }
        else
        {
            temp = temp->next;
        }
    }
}
int main()
{

    Node *head = new Node(10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 30);
    insertAtEnd(head, 30);
    insertAtEnd(head, 50);
    cout << endl;
    removeDuplicate(head);
    print(head);
    return 0;
}