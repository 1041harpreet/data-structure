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
void deletionAtHead(Node* &head){
    Node* temp=head;
    head=head->next;
    delete temp;
}
void deletionAtEnd(Node* head){
     Node* curr=head;
    while (head->next !=NULL)
    {
        curr=head;
        head=head->next;
    }
    curr->next=NULL;
    
    delete curr;
}
void deletionAtMiddle(Node* head,int index){
    
    int i=0;
    Node* curr=head;
    while (i <index)
    {
        curr=head;
        head=head->next;
        i++;
    }
    curr->next=head->next;
    delete curr;
}
int main(){
    Node* head=new Node(10);
    Node* second=new Node(15);
    Node* third= new Node(30);
    head->next=second;
    second->next=third;
    print(head);
    // deletionAtHead(head);
    // deletionAtEnd(head);
    deletionAtMiddle(head,1);

    cout<<endl;
    print(head);
    return 0;
}