//1 add all in vector and then sort vecotr
//time com. O(n*klog(n*k)) and space for vector O(n*k)

//2 optimal
// solution using min heap with k elements, time complexity is still same as above but we can optimize it

#include <queue>
#include<vector>
using namespace std;
/************************************************************

    Following is the linked list node structure

    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

class compare {
public:
  bool operator()(Node<int> *a, Node<int> *b) { return a->data > b->data; }
};
Node<int> *mergeKLists(vector<Node<int> *> &arr) {
  // Node* node=new Node();
  int k = arr.size();
  priority_queue<Node<int> *, vector<Node<int> *>, compare> minHeap;
  for (int i = 0; i < k; i++) {
    if (arr[i] != NULL) {
      Node<int> *temp = arr[i];
      minHeap.push(temp);
    }
  }
  Node<int> *head = NULL;
  Node<int> *tail = NULL;
  while (minHeap.size() > 0) {
    Node<int> *top = minHeap.top();
    minHeap.pop();
    if (top->next != NULL) {
      minHeap.push(top->next);
    }
    if (head == NULL) {
      head = tail = top;

    } else {
      tail->next = top;
      tail = top;
    }
  }

  return head;
}
//tc o(n*klog(k))
//sc O(k)