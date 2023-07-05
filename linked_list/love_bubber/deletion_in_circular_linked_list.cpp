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
void printList(Node *head)
{
    Node *temp = head;

    // If linked list is not empty
    if (head != NULL)
    {

        // Print nodes till we reach first node again
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    }
}
void print(Node *head)
{
    if (head == NULL)
    {
        cout << "empty" << endl;
    }
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

void deletionInCircular(Node *&head, int data)
{
    if (head == NULL)
    {
        return;
    }
    // if only single node
    if (head->data = data && head->next == head)
    {
        head = NULL;
        return;
    }

    Node *temp = head;
    Node *pre = NULL;

    // if head is deleted node
    if (head->data == data)
    {
        while (temp != head)
        {
            pre = temp;
            temp = temp->next;
        }
        temp->next = head->next;
        free(head);
        head = temp->next;
        return;
    }

    // if not found and reach at the end
    while (temp->next != head && temp->next->data != data)
    {
        pre = temp;
        temp = temp->next;
    }
    if (temp->next->data = data)
    {
        cout << "find the node" << endl;
        pre = temp->next;
        temp->next = pre->next;
        free(pre);
        return;
    }
    else
    {
        cout << "no element found" << endl;
    }

    // if found
}
int main()
{

    Node *head = new Node(20);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);
    insertAtEnd(head, 50);
    cout << endl;
    // adding a loop for the sake
    // of this example
    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    // loop added;
    temp->next = head;
    printList(head);
    cout << endl;
    deletionInCircular(head, 40);
    printList(head);

    return 0;
}