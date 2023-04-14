#include<iostream>
using  namespace std;
//node structure
struct node{
    int data;
    struct node* next;
};

void print(node* first){
    while (first !=NULL)
    {
       cout<<first->data<<endl;
       first=first->next;
    }   
}
//insertion 
struct node* insertAtFirst(node* head){
    node* newNode=(struct node* )malloc(sizeof(struct node));
    newNode->next=head;
    newNode->data=5;
    head=newNode;
    return head;
}
node* insertAtLast(node* head){
    node* newnode=(struct node*)malloc(sizeof(struct node));
    while(head!=NULL){
        head=head->next;
    }
    head->next=newnode;
    newnode->data=0;
    newnode->next=NULL;
   return newnode;
}
int main(){
    //memory allocate
    node* head=(struct node*)malloc(sizeof(struct node));
    node* first=(struct node*)malloc(sizeof(struct node));
    node* second=(struct node*)malloc(sizeof(struct node));
    head->data=1;
    head->next=first;
    first->data=2;
    first->next=second;
    second->data=3;
    second->next=NULL;
    print(head);
    // struct node* temp=insertAtFirst(head);
    // cout<<"after "<<endl;
    // print(temp);
    node* temp=insertAtLast(head);
    print(temp);
    return 0;
}