#include <iostream>
using namespace std;
class Stack
{
public:
    int top1, top2, size, *arr;
    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }
    void push1(int data)
    {
        // top=5 ,size=5 , top1=-1;
        if (top2 - top1 > 1)
        {
            top1++;
            arr[top1] = data;
        }
        else
        {
            cout << "stack overflow" << endl;
        }
    }
    void push2(int data)
    {
        // top=5 ,size=5 , top1=-1;
        if (top2 - top1 > 1)
        {
            top2--;
            arr[top2] = data;
        }
        else
        {
            cout << "stack overflow" << endl;
        }
    }
    void pop1(){
        if(top1==1){
            cout<<"underflow"<<endl;
        }else{
            int x=arr[top1];
            
            top1--;
        }
    }
     void pop2(){
        if(top2==size){
            cout<<"underflow"<<endl;
        }else{
            int x=arr[top2];
            
            top2++;
        }
    }
};
int main()
{
    Stack st(5);
    st.push1(1);
    st.push1(2);
    st.push1(3);
    st.push1(4);
    st.push2(2);
    st.pop1();
    st.pop2();
    st.push2(3);
    st.push2(4);
    st.push2(5);
    // st.push2(6);
    // st.push2(1);
    // st.push1(5);
    // st.push1(2);

    return 0;
}