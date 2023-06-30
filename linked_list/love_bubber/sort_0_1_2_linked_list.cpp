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
struct Node *deleteAtFirst(struct Node *head)
{
    head = head->next;
    return head;
}
void sortLinkedList012(Node *head)
{
    if (head == NULL || head->next == NULL)
        return;

    // calculate occurance :
    map<int, int> mp;
    Node *temp = head;
    Node *newHead = new Node(4);
    while (temp != NULL)
    {
        mp[temp->data]++;
        // cout<<"value of "<<temp->data<<" is "<<mp[temp->data]<<endl;
        temp = temp->next;
    }
    for (auto it : mp)
    {
        cout << "value of " << it.second << endl;
        for (int i = 0; i < it.second; i++)
        {
            cout << "value of sub " << it.first << endl;
            insertAtEnd(newHead, it.first);
        }
    }
    Node *n = deleteAtFirst(newHead);
    print(n);
}

// using count
Node *sortUsingCount(Node *head)
{
    int zero_count = 0;
    int one_count = 0;
    int two_count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            zero_count++;
        }
        else if (temp->data == 1)
        {
            one_count++;
        }
        else
        {
            two_count++;
        }
        temp = temp->next;
    }
    temp = head;
    while (temp != NULL)
    {
        if (zero_count != 0)
        {
            temp->data = 0;
            zero_count--;
        }
        else if (one_count != 0)
        {
            temp->data = 1;
            one_count--;
        }
        else
        {
            temp->data = 2;
            two_count--;
        }
        temp = temp->next;
    }

    return head;
}

void insertIntoTail(Node *&tail, Node *curr)
{
    // insert the current node at end of list
    tail->next = curr;
    tail = curr;
}

// using changing links
Node* sortusingChangingLinks(Node *head)
{
    Node *zerohead = new Node(-1);
    Node *oneHead = new Node(-1);
    Node *twoHead = new Node(-1);
    Node *zeroTail = zerohead;
    Node *oneTail = oneHead;
    Node *twoTail = twoHead;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
        {

            insertIntoTail(zeroTail, temp);
        }
        else if (temp->data == 1)
        {
            insertIntoTail(oneTail, temp);
        }
        else
        {
            insertIntoTail(twoTail, temp);
        }
        temp = temp->next;
    }

    // merge all nodes
    if (oneHead->next != NULL)
    {
        zeroTail->next = oneHead->next;
    }
    else
    {
        zeroTail->next = twoHead->next;
    }
    oneTail->next = twoHead->next;
    twoTail->next = NULL;
    head = zerohead->next;
    delete zerohead;
    delete oneHead;
    delete twoHead;
    return head;
}
int main()
{

    Node *head = new Node(1);
    insertAtEnd(head, 0);
    insertAtEnd(head, 0);
    insertAtEnd(head, 2);
    insertAtEnd(head, 2);
    insertAtEnd(head, 1);

    cout << endl;
    Node *temp = head;
    // print(head);
    // sortLinkedList012(head);
    // Node *n = sortUsingCount(head);
    // print(n);
    Node* n=sortusingChangingLinks(head);
    print(n);
    return 0;
}