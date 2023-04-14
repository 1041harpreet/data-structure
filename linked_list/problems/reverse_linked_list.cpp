#include<iostream>
using namespace std;
struct node{
    int data;
    struct node* next;
};
void print(struct node* head){
    while(head !=NULL){
        cout<<head->data<<endl;
        head=head->next;
    }
}

struct node* reverseList(struct node* head){
    struct node* second=(struct node*)malloc(sizeof(struct node));
    struct node* current;
    struct node* previous;
    struct node* Next;
    current=head;
    previous=NULL;
    Next=NULL;
    while (current !=NULL)
    {
        
        Next=current->next;
        current->next=previous;
        previous=current;
        current=Next;
    }
    return previous;
}

int main() {
    struct node* head1=(struct node *)malloc(sizeof(struct node));
    struct node* first1=(struct node *)malloc(sizeof(struct node));
    struct node* second1=(struct node *)malloc(sizeof(struct node));
    struct node* head2=(struct node *)malloc(sizeof(struct node));
    struct node* first2=(struct node *)malloc(sizeof(struct node));
    struct node* second2=(struct node *)malloc(sizeof(struct node));

    //for first list
    head1->data=1;
    head1->next=first1;
    first1->data=2;
    first1->next=second1;
    second1->data=3;
    second1->next=NULL;

    //for second list
     head2->data=4;
    head2->next=first2;
    first2->data=5;
    first2->next=second2;
    second2->data=6;
    second2->next=NULL;
    //print first list
    cout<<"first list is"<<endl;
    print(head1);
    // cout<<"second list is"<<endl;
    // print(head2);
    //after addition
    cout<<"after"<<endl;
   struct node * newNode=reverseList(head1);
   print(newNode);
   
}