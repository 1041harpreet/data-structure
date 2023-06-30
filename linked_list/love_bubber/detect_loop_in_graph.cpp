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
bool detectLoop(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return false;
    }
    map<int, bool> visited;
    bool isLoop = false;
    Node *current = head;
    while (current != NULL)
    {

        if (visited[current->data] == true)
        {
            cout<<"loop at "<<current->data<<endl;
            return true;
        }
        visited[current->data] = true;
        current = current->next;
    }
    return false;
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

    bool loopStart = detectLoop(head);
    if (!loopStart)
        cout << "Loop does not exists" << endl;
    else
    {
        cout << "Loop exist" << endl;
    }

    return 0;
}