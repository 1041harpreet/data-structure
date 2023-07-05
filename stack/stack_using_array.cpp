#include <iostream>
using namespace std;
class Stack
{
public:
    int top, size, *arr;
    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    void push(int data)
    {
        if (top == size - 1)
        {
            cout << "Stack overflow\n";
        }
        else
        {
            top++;
            arr[top] = data;
        }
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "\nUnderflow!!!\n";
        }
        else
        {
            --top;
        }
    }
    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int peek()
    {
        if (top >= 0)
        {
            return arr[top];
        }else{
            cout<<"stack is empty";
            return -1;
        }
    }
};
int main()
{
    Stack st(5);
    st.push(2);
    st.push(1);
    st.push(1);
    st.push(1);
    st.push(5);
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    // st.pop();
    // st.isEmpty() ? cout << "empty" : cout << "not empty" << endl;
    // st.pop();
    // st.push(1);
    // cout<<st.size;
    cout<<st.peek()<<endl;
    return 0;
}