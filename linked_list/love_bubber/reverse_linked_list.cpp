#include<iostream>
using namespace std;
class Node{
    public:
      int data;
      Node* next;
    Node(int data){
        this->data=data;
        next = NULL;
    }  
};
void print(Node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head ->next ;
    }
}

void insertAtEnd(Node* head,int data){
     Node* node=new Node(data);
    while (head->next !=NULL)
    {
        head=head->next;
    }
    head->next=node;
    
}


// Node* reverseLinkedList(Node* head){
//    if(head==NULL || head->next==NULL){
//     return head;
//    }
//    Node* curr=head;
//    Node* next=NULL;
//    Node* prev=NULL;
//    while (curr !=NULL)
//    {
//       next=curr->next;
//       curr->next=prev;
//       prev=curr;
//       curr=next;
      
//    }
// return prev;
// }
Node* reverseLinkedList(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* newhead=reverseLinkedList(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
}
int main(){
    Node* head=new Node(10);
    insertAtEnd(head,20);
    insertAtEnd(head,30);
    insertAtEnd(head,40);
    insertAtEnd(head,50);
    cout<<endl;
    print(head);
    Node* v=reverseLinkedList(head);
    cout<<endl;
    print(v);

    return 0;
}