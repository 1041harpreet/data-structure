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

int lengthOfLinkedList(Node* head){
    int count=0;
   while (head !=NULL)
   {
      count++;
      head=head->next;
   }
   
    return count;
}
int middleElement(Node* head){
    if(head ==NULL){
        return head->data;
    }
    int length=lengthOfLinkedList(head);
    // cout<<length;
    int mid=(length/2);
    // if(mid % 2 ==0){
    //     mid=mid+1;
    // }
    for (int i = 0; i < mid; i++)
        {
            head=head->next;
        }
        return head->data;
}

int main(){
    Node* head=new Node(10);
    insertAtEnd(head,20);
    insertAtEnd(head,30);
    insertAtEnd(head,40);
    insertAtEnd(head,35);
    insertAtEnd(head,50);
    cout<<endl;
    // print(head);
    cout<<"middle element is "<<middleElement(head);
    cout<<endl;


    return 0;
}