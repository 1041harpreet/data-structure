#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
void print(struct node *head)
{
    while (head != NULL)
    {
        cout << head->data << endl;
        head = head->next;
    }
}

// function takes two linked lists as input
node *merged_linkedlist(node *head1, node *head2)
{
    node *temp = NULL;
    if (head1->data <= head2->data)
    {
        temp = head1;
    }
    else
    {
        temp = head2;
    }

    //    //Check if any linked list is empty
    //    if (head1 == nullptr) {
    //      return head2;
    //    } else if (head2 == nullptr) {
    //     return head1;
    //    }

    //    //head pointer for merged linked list
    //    node* newhead = nullptr;

    //    //check for smallest element by comparing first two elements
    //    //of both linked lists
    //    if (head1->data <= head2->data) {

    //      newhead = head1;
    //      //moving head 1 to point to next element in the
    //      //linked list 1 for further comparison
    //      head1 = head1->next;

    //    } else {

    //      newhead = head2;
    //      //moving head 2 to point to next element in the
    //      //linked list 2 for further comparison
    //      head2 = head2->next;

    //    }

    //    //new pointer to move forward and store new elements and
    //    //keeping head pointer of new linked list as it is
    //    node* temphead = newhead;

    //    //run the loop until we reach last element of both lists
    //    while (head1 != nullptr && head2 != nullptr) {
    //      node* temp = nullptr;
    //      if (head1->data <= head2->data) {
    //        temp = head1;
    //        head1 = head1->next;
    //      } else {
    //        temp = head2;
    //        head2 = head2->next;
    //      }

    //      //store the next element and move forward to new node
    //      temphead->next = temp;
    //      temphead = temp;
    //    }

    //    //if any element is left then add it to final linked list
    //    if (head1 != nullptr) {
    //      temphead->next = head1;
    //    } else if (head2 != nullptr) {
    //      temphead->next = head2;
    //    }

    //    return newhead;
}

int main()
{
    struct node *head1 = (struct node *)malloc(sizeof(struct node));
    struct node *first1 = (struct node *)malloc(sizeof(struct node));
    struct node *second1 = (struct node *)malloc(sizeof(struct node));
    struct node *head2 = (struct node *)malloc(sizeof(struct node));
    struct node *first2 = (struct node *)malloc(sizeof(struct node));
    struct node *second2 = (struct node *)malloc(sizeof(struct node));

    // for first list
    head1->data = 1;
    head1->next = first1;
    first1->data = 3;
    first1->next = second1;
    second1->data = 5;
    second1->next = NULL;

    // for second list
    head2->data = 1;
    head2->next = first2;
    first2->data = 2;
    first2->next = second2;
    second2->data = 5;
    second2->next = NULL;
    // print first list
    cout << "first list is" << endl;
    print(head1);
    cout << "second list is" << endl;
    print(head2);
    // after merge
    cout << "after merge";
    struct node *newList = merged_linkedlist(head1, head2);
    cout << "after merge" << endl;
    print(newList);
}