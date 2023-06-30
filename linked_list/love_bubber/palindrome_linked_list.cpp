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
Node *reverseLinkedList(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *curr = head;
    Node *next = NULL;
    Node *prev = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
Node *getMid(Node *head)
{
    Node *slow_ptr = head;
    Node *fast_ptr = head->next;

    while (fast_ptr != NULL && fast_ptr->next != NULL)
    {
        fast_ptr = fast_ptr->next->next;
        slow_ptr = slow_ptr->next;
    }

    return slow_ptr;
}
// using reverse
bool CheckPalindrome(Node *head)
{

    if (head->next == NULL)
        return true;

    // find middle
    Node *mid = getMid(head);
    // reverse a linked list after middle
    Node *temp = mid->next;
    mid->next = reverseLinkedList(temp);

    //  cout<<endl;
    Node *head1 = head;
    Node *head2 = mid->next;
    while (head2 != NULL)
    {
        if (head1->data != head2->data)
        {
          
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    temp = mid->next;
    mid->next = reverseLinkedList(temp);
    return true;
}
// 2 create array ,copy element ,use array palindrome sc. O(n)
int main()
{
    Node *head = new Node(0);
    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 2);
    insertAtEnd(head, 1);
    insertAtEnd(head, 0);
    cout << endl;
    print(head);
    cout << endl;
    cout << CheckPalindrome(head);
    return 0;
}