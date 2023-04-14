// // basic tree traversal using level order :
// // 1 using recursion :
// #include <iostream>
// using namespace std;
// struct Node
// {
//   int data;
//   struct Node *left;
//   struct Node *right;
// };
// int height(Node* node);
// void printCurrentOrder(Node* root,int i);
// void levelOrder(Node* root){

//      if(root == NULL){
//         return ;
//     }
//     int h=height(root);
//     for(int i=1;i<=h;i++){
//        printCurrentOrder(root,i);
//     }
// }
// void printCurrentOrder(Node* root,int level){
//     if(root == NULL){
//     return;
//     }
//     if(level==1){
//         cout<<root->data<<' ';
//     }
//     else if(level >1){
//         printCurrentOrder(root->left,level-1);
//         printCurrentOrder(root->right,level-1);
//     }
// }
// int height(Node* root){
//     if(root == NULL){
//     return 0;
//     }
//     int left=height(root->left);
//     int right=height(root->right);
//     if(left>right){
//         return left+1;
//     }else{
//         return right+1;
//     }

// }
// int main()
// {
//   struct Node *head;
//   struct Node *second;
//   struct Node *third;
//   struct Node *fourth;
//   struct Node *fifth;
//   struct Node *sixth;
//   struct Node *seventh;
//   // allocate 3 nodes in the heap
//   head = (struct Node *)malloc(sizeof(struct Node));
//   second = (struct Node *)malloc(sizeof(struct Node));
//   third = (struct Node *)malloc(sizeof(struct Node));
//   fourth = (struct Node *)malloc(sizeof(struct Node));
//   fifth = (struct Node *)malloc(sizeof(struct Node));
//   sixth = (struct Node *)malloc(sizeof(struct Node));
//   seventh = (struct Node *)malloc(sizeof(struct Node));
//   head->data = 10;     // assign data in first node
//   head->left = second; // Link first node with second
//   head->right = third;
//   second->data = 5;
//   third->data = 15;      // assign data in first node
//   second->left = fourth; // Link first node with second
//   second->right = fifth;
//   third->left = sixth; // Link first node with second
//   third->right = seventh;
//   fourth->data = 2;
//   fifth->data = 7;
//   sixth->data = 12;
//   seventh->data = 18;
//   fourth->left = NULL;
//   fourth->right = NULL;
//   fifth->left = NULL;
//   fifth->right = NULL;
//   sixth->left = NULL;
//   sixth->right = NULL;
//   seventh->left = NULL;
//   seventh->right = NULL;
//   levelOrder(head);
//   return 0;
// }

// basic tree traversal using level order :
// 1 using recursion :
#include <iostream>
#include <queue>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

void levelOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
            // q.pop();
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right )
            {
                q.push(temp->right);
            }
        }
    }
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fifth;
    struct Node *sixth;
    struct Node *seventh;
    // allocate 3 nodes in the heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    fifth = (struct Node *)malloc(sizeof(struct Node));
    sixth = (struct Node *)malloc(sizeof(struct Node));
    seventh = (struct Node *)malloc(sizeof(struct Node));
    head->data = 10;     // assign data in first node
    head->left = second; // Link first node with second
    head->right = third;
    second->data = 5;
    third->data = 15;      // assign data in first node
    second->left = fourth; // Link first node with second
    second->right = fifth;
    third->left = sixth; // Link first node with second
    third->right = seventh;
    fourth->data = 2;
    fifth->data = 7;
    sixth->data = 12;
    seventh->data = 18;
    fourth->left = NULL;
    fourth->right = NULL;
    fifth->left = NULL;
    fifth->right = NULL;
    sixth->left = NULL;
    sixth->right = NULL;
    seventh->left = NULL;
    seventh->right = NULL;
    levelOrder(head);
    return 0;
}