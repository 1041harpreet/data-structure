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

// detect loop in graph
Node *detectLoop(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
        if (slow == fast)
        {
            return slow;
        }
    }
    return NULL;
}
Node *getStartingNode(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *intersection = detectLoop(head);
    Node *slow = head;
    while (slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }

    return slow;
}
void removeLoop(Node *head)
{
    if (head == NULL)
    {
        return;
    }

    Node *starting_node = getStartingNode(head);
    Node *temp = starting_node;
    while (temp->next != starting_node)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    // delete starting_node;
}
int main()
{

    Node *head = new Node(10);
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
    temp->next = head->next;
    Node *n = detectLoop(head);
    if (n != NULL)
    {
        cout << "loop is present" << endl;
        Node *loop = getStartingNode(head);
        if (loop != NULL)
        {
            cout << "loop at element " << loop->data << endl;
        }
        removeLoop(head);
        print(head);
    }
    else
    {
        cout << "loop is not present" << endl;
    }
    // bool loopStart = detectLoop(head);
    // if (!loopStart)
    //     cout << "Loop does not exists" << endl;
    // else
    // {
    //     cout << "Loop exist" << endl;
    // }

    return 0;
}