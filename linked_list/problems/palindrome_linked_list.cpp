#include<iostream>
#include <bits/stdc++.h>
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

bool checkPalindrome(struct node* head){
    // 1 2 3 2 1
    stack<int> s;
    node* temp=head;
    while (temp !=NULL)
    {
       s.push(temp->data);
       temp=temp->next;
    }
    while (head !=NULL)
    {
        int i=s.top();
        s.pop();
        if(head->data != i){
            return false;
        }
       head=head->next;
        }
    
    return true;
}

int main() {
    struct node* head1=(struct node *)malloc(sizeof(struct node));
    struct node* first1=(struct node *)malloc(sizeof(struct node));
    struct node* second1=(struct node *)malloc(sizeof(struct node));
    struct node* third1=(struct node *)malloc(sizeof(struct node));


    //for first list
    head1->data=1;
    head1->next=first1;
    first1->data=2;
    first1->next=second1;
    second1->data=3;
    second1->next=third1;
    third1->data=1;
    third1->next=NULL;
    //print first list
    cout<<"first list is"<<endl;
    print(head1);
    //after palindrome checking
    int result=checkPalindrome(head1);
 
    if (result == 1)
        cout << "isPalindrome is true\n";
    else
        cout << "isPalindrome is false\n";
}