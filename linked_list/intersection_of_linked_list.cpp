
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
    if(head==NULL){
        cout<<"empty";
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
Node *findIntersection(Node *head1, Node *head2)
{
    Node *temp = new Node(-1);
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data == head2->data)
        {
            cout<<"calling for"<<head1->data<<endl;
            insertAtEnd(temp, head1->data);
            head2 = head2->next;
            head1 = head1->next;
        }
        else if (head1->data > head2->data)
        {
            head2 = head2->next;
        }
        else
        {
            head1 = head1->next;
        }
    }
    return temp->next;
}

int main()
{

    Node *head1 = new Node(10);
    insertAtEnd(head1, 10);
    insertAtEnd(head1, 30);

    cout << endl;
    Node *head2 = new Node(10);
    insertAtEnd(head2, 20);
    insertAtEnd(head2, 30);

    Node *result = findIntersection(head1, head2);
    // cout<<result->data;
    print(result);

    cout << endl;
    return 0;
}
