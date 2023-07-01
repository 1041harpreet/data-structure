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
Node *reverseLinkedList(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *newhead = reverseLinkedList(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;
}
Node *sumOfLinkedList(Node *firstHead, Node *secondHead)
{
    if (firstHead == NULL)
    {
        return secondHead;
    }
    if (secondHead == NULL)
    {
        return firstHead;
    }
    firstHead = reverseLinkedList(firstHead);
    secondHead = reverseLinkedList(secondHead);
    int carry = 0;
    Node *ans = new Node(0);
    while (firstHead != NULL && secondHead != NULL)
    {
        int sum = carry + firstHead->data + secondHead->data;
        carry = sum / 10;
        int data = sum % 10;
        insertAtEnd(ans, data);
        firstHead = firstHead->next;
        secondHead = secondHead->next;
    }
    while (firstHead != NULL)
    {
        int sum = carry + firstHead->data;
        carry = sum / 10;
        int data = sum % 10;
        insertAtEnd(ans, data);
        firstHead = firstHead->next;
    }
    while (secondHead != NULL)
    {
        int sum = carry + secondHead->data;
        carry = sum / 10;
        int data = sum % 10;
        insertAtEnd(ans, data);
        secondHead = secondHead->next;
    }
    if (carry != 0)
    {
        insertAtEnd(ans, carry);
    }
    // print(ans);
    ans=reverseLinkedList(ans->next);
    return ans;
}
int main()
{

    Node *firsthead = new Node(9);
    insertAtEnd(firsthead, 0);
    insertAtEnd(firsthead, 0);
    Node *secondhead = new Node(2);
    insertAtEnd(secondhead, 2);
    insertAtEnd(secondhead, 2);
    insertAtEnd(secondhead,2);
    Node* n=sumOfLinkedList(firsthead, secondhead);
    print(n);
    return 0;
}