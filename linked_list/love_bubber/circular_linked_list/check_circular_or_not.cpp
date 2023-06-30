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
bool isCircular(Node* head){
    if(head==NULL){
        return true;
    }
    if(head->next==NULL){
        return false;
    }
    Node* curr=head->next;
    while (curr !=NULL && curr !=head)
    {
       curr=curr->next;
    }
    if(curr=NULL){
        return false;
    }
    if(curr==head){
        return true;
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
    // print(head);
    bool ans=isCircular(head);
    if(ans){
        cout<<"circular linked list"<<endl;
    }else{
        cout <<"not circular linked list"<<endl;
    }
    return 0;
}