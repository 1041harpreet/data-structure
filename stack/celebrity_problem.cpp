//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    bool knows(int A, int B,vector<vector<int>>M) 
    { 
    return M[A][B]; 
    
    }

    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
    int celebrity = -1;

    // Check one by one whether the person is a celebrity or not.
    for(int i = 0; i < n; i++) {
        bool knowAny = false, knownToAll = true;

        // Check whether person with id 'i' knows any other person.
        for(int j = 0; j < n; j++) {
            if(knows(i, j,M)) {
                knowAny = true;
                break;
            }
        }

        // Check whether person with id 'i' is known to all the other person.
        for(int j = 0; j < n; j++) {
            if(i != j and !knows(j, i,M)) {
                knownToAll = false;
                break;
            }
        }

        if(!knowAny && knownToAll) {
            celebrity = i;
            break;
        }
    }

    return celebrity;
    
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
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
