//get min in O(1) and O(1) space 
//1 store min element in stack for every level but it is not O(1#include <stack>
#include<iostream>
#include <limits.h>
using namespace std;
class SpecialStack {
    stack<int>s;
    int mini=INT_MIN;

    // Define the data members.

    /*----------------- Public Functions of SpecialStack -----------------*/
    public:
        
    void push(int data) {
        if(s.empty()){
            s.push(data);
            mini=data;
        }
        else{
           if(data<mini){
               s.push(2*data-mini);
               mini=data;
           }
        else{
               s.push(data);
           }
        }
        // Implement the push() function.
    }

    int pop() {
        if(s.empty()){
            return -1;
        }
        int curr=s.top();
        s.pop();
        if(curr < mini){
            int prev=mini;
            int value=2*prev-curr;
            mini=value;
            return prev;

        }else{
            return curr;
        }
        // Implement the pop() function.
    }

    int top() {
        if(s.empty()){
            return -1;
        }
        int curr=s.top();
        if(curr < mini){
            return mini;
        }else{
            return curr;
        }
        // Implement the top() function.
    }

    bool isEmpty() {
        return s.empty();
        // Implement the isEmpty() function.
    }

    int getMin() {
        if(s.empty()){
            return  -1;
        }
        return mini;
        // Implement the getMin() function.
    }  
};