//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.

    void createMapping(int in[],map<int,int>&nodeToIndex,int n){
        for(int i=0;i<n;i++){
            nodeToIndex[in[i]]=i;
        }
    }
    
    Node* solve(int in[],int post[],int n,int &index,int startingIndex,int endingIndex,map<int,int>&nodeToIndex){
         if(startingIndex > endingIndex || index < 0){
            return NULL;
        }
        int element=post[index--];
        Node* root=new Node(element);
        int pos=nodeToIndex[element];
        
        //recursive calls
        root->right=solve(in,post,n,index,pos+1,endingIndex,nodeToIndex);
        root->left=solve(in,post,n,index,startingIndex,pos-1,nodeToIndex);
        return root;
        
    }
Node *buildTree(int in[], int post[], int n) {
        int index=n-1;
        map<int,int>nodeToIndex;
        createMapping(in,nodeToIndex,n);
        Node* ans=solve(in,post,n,index,0,n-1,nodeToIndex);
        return ans;
}
