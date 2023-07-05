
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void print(Node *head)
{
    if (head == NULL)
    {
        cout << "empty";
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
int lengthOfLinkedList(Node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }

    return count;
}
int printNthNode(Node *head, int index)
{
    if (head == NULL)
    {
        return -1;
    }
    int l = lengthOfLinkedList(head);
    if (l < index)
    {
        return -1;
    }
    int i = l - index;

    int j = 0;
    while (i > j)
    {
        head = head->next;
        i=i-1;
    }

    return head->data;
}

int main()
{

    Node *head1 = new Node(10);
    insertAtEnd(head1, 10);
    insertAtEnd(head1, 30);
    cout << "element is : " << printNthNode(head1, 1);
    cout << endl;
    return 0;
}
