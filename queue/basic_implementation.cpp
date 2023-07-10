#include <bits/stdc++.h> 
#include<iostream>
using namespace std;
class Queue {
    int *arr;
    int size;
    int qfront;
    int rear;
public:
    Queue() {
        size=100001;
        arr=new int[size];
        qfront=rear=0;
        // Implement the Constructor
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if(qfront==rear){
            return true;
        }else{
            return false;
        }
        // Implement the isEmpty() function
    }

    void enqueue(int data) {
        //check queue emty or not
        if(rear==size){
            cout<<"queue is full";
        }else{
            arr[rear]=data;
            rear++;
        }
     
            
        // Implement the enqueue() function
    }

    int dequeue() {
        if(qfront==rear){
            return -1;
        }
        int element=arr[qfront];
        arr[qfront]=-1;
        qfront++;
        if(qfront==rear){
            qfront=0;
            rear=0;
        }
        return element;
        // Implement the dequeue() function
    }

    int front() {
        if(qfront==rear){
            return -1;
        }
        return arr[qfront];
        // Implement the front() function
    }
};