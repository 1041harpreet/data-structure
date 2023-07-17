//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends


class Solution{
    public:
    void createMapping(int in[],map<int,int>&nodeToIndex,int n){
        for(int i=0;i<n;i++){
            nodeToIndex[in[i]]=i;
        }
    }
  
    Node* solve(int in[],int pre[],int n,int &index,int startingIndex,int endingIndex,map<int,int>& nodeToIndex){
         if(startingIndex > endingIndex || index >= n){
            return NULL;
        }
        int element=pre[index++];
        Node* root=new Node(element);
        int pos=nodeToIndex[element];
        
        //recursive calls
        root->left=solve(in,pre,n,index,startingIndex,pos-1,nodeToIndex);
        root->right=solve(in,pre,n,index,pos+1,endingIndex,nodeToIndex);
        return root;
        
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        int index=0;
        map<int,int>nodeToIndex;
        createMapping(in,nodeToIndex,n);
        Node* ans=solve(in,pre,n,index,0,n-1,nodeToIndex);
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends