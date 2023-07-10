#include <bits/stdc++.h> 
class NStack
{
    int *arr;
    int *top;
    int *next;
    int freeIndex;
public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        int n=N;
        int s=S;
        arr= new int[s];
        top =new int[n];
        next=new int[s];
        for(int i=0; i <n;i++){
            top[i]=-1;
        }
        for(int i=0; i <s;i++){
            next[i]=i+1;
        }
        next[s-1]=-1;
        freeIndex=0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        if(freeIndex==-1){
            return false;
        }
        //find index
        int index=freeIndex;

        //change freeindex
        freeIndex=next[index];

        //insert eleement
        arr[index]=x;

        //change next
        next[index]=top[m-1];

        //change top
        top[m-1]=index;

        return true;
        
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        if(top[m-1]==-1){
            return -1;
        }
        int index=top[m-1];

        top[m-1]=next[index];

        next[index]=freeIndex;
         
        freeIndex=index;

        return arr[index]; 
    }
};