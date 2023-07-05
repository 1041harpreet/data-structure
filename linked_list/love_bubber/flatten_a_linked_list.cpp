#include<iostream>
using namespace std;
class Node{
    public:
      int data;
      Node* down;
      Node* right;
    Node(int data){
        this->data=data;
        down = NULL;
        right=NULL;
    }  
};
void print(Node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head ->down ;
    }
}

void insertAtEnd(Node* head,int data){
     Node* node=new Node(data);
    while (head->down !=NULL)
    {
        head=head->down;
    }
    head->down=node;
    
}

Node* merge(Node* a, Node* b)
{
 
    // If first linked list is empty then second
    // is the answer
    if (a == NULL)
        return b;
 
    // If second linked list is empty then first
    // is the result
    if (b == NULL)
        return a;
 
    // Compare the data members of the two linked
    // lists and put the larger one in the result
    Node* result;
 
    if (a->data < b->data) {
        result = a;
        result->down = merge(a->down, b);
    }
 
    else {
        result = b;
        result->down = merge(a, b->down);
    }
    result->right = NULL;
    return result;
}
Node* flattenLinkedList(Node* root){
    // Base Cases
    if (root == NULL || root->right == NULL)
        return root;
 
    // Recur for list on right
    root->right = flattenLinkedList(root->right);
 
    // Now merge
    root = merge(root, root->right);
 
    // Return the root
    // it will be in turn merged with its left
    return root;
}

int main(){
    Node* head=new Node(10);
    insertAtEnd(head,20);
    insertAtEnd(head,30);
    insertAtEnd(head,40);
    insertAtEnd(head,50);
    cout<<endl;
    print(head);
    cout<<endl;
   

    return 0;
}