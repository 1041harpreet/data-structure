#include <iostream>
#include <queue>
using namespace std;
class n_queue_problem
{
private:
    int *arr;
    int size;
    int k;
    int *front;
    int *rear;
    int *next;
    int freespot;

public:
    n_queue_problem(int k, int size)
    {
        this->size = size;
        this->k = k;
        front = new int[k];
        rear = new int[k];
        for (int i = 0; i < k; i++)
        {
            front[i] = -1;
            rear[i] = -1;
        }

        next = new int[size];
        for (int i = 0; i < size - 1; i++)
        {
            next[i] = i + 1;
        }
        next[size - 1] = -1;
        arr = new int[size];
        freespot = 0;
    }

    void enqueue(int data, int qn)
    {
        if (freespot == -1)
        {
            cout << "queue is full" << endl;
            return;
        }
        // find firest free index;
        int index = freespot;
        freespot = next[index];
        // check is first element
        if (front[qn - 1] == -1)
        {
            front[qn - 1] = index;
        }
        else
        {
            // link to next data
            next[rear[qn - 1]] = index;
        }
        next[index] = -1;
        // update last node of queue.
        rear[qn - 1] = index;
        // store the value in array at that position.
        arr[index] = data;
    }
    int dequeue(int qn){
        if(front[qn-1]==-1){
            cout<<"underflow condition"<<endl;
            return -1;
        }
        int index=front[qn-1];
        front[qn-1]=next[index];
        next[index]=freespot;
        freespot=index;
        return front[index];
    }
};

int main()
{
    n_queue_problem q=n_queue_problem(3,10);
    q.enqueue(1,1);
    q.dequeue(1);
    q.dequeue(1);

    return 0;
}