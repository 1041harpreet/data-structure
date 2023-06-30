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
void insertAtHead(Node* &head,int data){
    Node* node=new Node(data);
    node->next=head;
    head=node;
}
void insertAtEnd(Node* head,int data){
     Node* node=new Node(data);
    while (head->next !=NULL)
    {
        head=head->next;
    }
    head->next=node;
    
}
void insertAtMiddle(Node* head, int data,int index){
    Node* node=new Node(data);
    int i=0;
    while (i <index-1)
    {
        head=head->next;
        i++;
    }
    node->next=head->next;
    head->next=node;
    

}
int main(){
    Node* head=new Node(10);
    Node* second=new Node(15);
    Node* third= new Node(30);
    head->next=second;
    second->next=third;
    print(head);
    // insertAtHead(head,10);
    // insertAtEnd(head,40);
    insertAtMiddle(head,25,2);
    cout<<endl;
    print(head);
    return 0;
}