#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Stack
{
public:
    Node *top = NULL;

    //     void insertAtHead(Node* &head,int data){
    //     Node* node=new Node(data);
    //     node->next=head;
    //     head=node;
    // }
    void push(int data)
    {
        Node *node = new Node(data);
        if (top == NULL)
        {
            top = node;
        }
        else
        {
            node->next = top;
            top = node;
        }
    }

    void printStack()
    {
        if (top == NULL)
        {
            cout << "stack underflow";
        }
        else
        {
            Node *temp = top;
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp=temp->next;
            }
          
        }
          cout << endl;
    }
   
    void pop()
    {
        if(top==NULL){
            cout<<"stack underflow"<<endl;
        }else{
             Node *temp=top;
             top=top->next;
             delete temp;
        }
    }
    bool isEmpty()
    {
        return !((bool)(top));
    }
    Node* peek()
    {
        return top;
    }
};
int main()
{
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.printStack();
    st.pop();
    st.pop();
    // st.pop();
    st.printStack();
    cout<<st.peek()->data;
    // cout<<"is empty : "<<st.isEmpty();
    return 0;
}