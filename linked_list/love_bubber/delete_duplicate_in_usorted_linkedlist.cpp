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
    Node *prev ;
    while (temp != NULL && temp->next != NULL)
    {
        Node *curr = temp;

        while (curr->next != NULL)
        {
            if (curr->next->data == temp->data)
            {
                prev = curr->next;
                curr->next= curr->next->next;
                delete (prev);
            }
            else
            {
                curr = curr->next;
            }
        }
        temp = temp->next;
    }
}
//2 solution : 1. sort the list 2. now use first approach ( O(nlogn))
// 3. using map ....use visited list O(n)
 
int main()
{

    Node *head = new Node(10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 30);
    insertAtEnd(head, 60);
    insertAtEnd(head, 30);
    cout << endl;
    removeDuplicate(head);
    print(head);
    return 0;
}