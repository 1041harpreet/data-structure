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

Node* ans(Node* firstHead,Node* secondHead){

    
    Node* curr1=firstHead;
    Node* next1=curr1->next;
    Node* curr2=secondHead;
    Node* next2=curr2->next;
    //if only one element is present in list
    if(firstHead->next ==NULL){
        firstHead->next=secondHead;
        return firstHead;
    }
    while (curr2 != NULL  && next1 !=NULL)
    {
        if((curr2->data >= curr1->data) && (curr2->data <= next1->data)){
            curr1->next=curr2;
            next2=curr2->next;
            curr2->next=next1;
            curr1=curr2;
            curr2=next2;
        }else{
            curr1=next1;
            next1=next1->next;
            if(next1 ==NULL){
                curr1->next=curr2;
                return firstHead;
            }
        }
    }
    return firstHead;
    
}
Node *mergeTwoSortedList(Node *&firstHead, Node *&secondhead)
{
    if (firstHead == NULL)
    {
        return secondhead;
    }
    if (secondhead == NULL)
    {
        return firstHead;
    }
    if (firstHead->data <=secondhead->data)
    {
        return ans(firstHead,secondhead);
    }else{
        return ans(secondhead,firstHead);
    }

}
// 2 using vector : push into vector , sort the vector

int main()
{

    Node *head = new Node(1);
    insertAtEnd(head, 2);
    Node *secondHead = new Node(2);
    insertAtEnd(secondHead, 3);

    cout << endl;
    Node *n = mergeTwoSortedList(head, secondHead);
    print(n);

    return 0;
}