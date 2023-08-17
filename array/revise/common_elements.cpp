//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
           vector<int> ans;
           int i=0,j=0,k=0;
           int last_element = INT_MIN; // Initialize with a value that's lower than any element
           //till any one array is not empty
           while(i<n1 && j<n2 && k<n3 ){
               //if matches
               if(A[i]==B[j] && B[j]==C[k] && A[i] !=last_element){
                   ans.push_back(A[i]);
                   last_element=A[i];
                   i++;
                   j++;
                   k++;
               }
               //if a element is smaller than b increase i++   x<y
               else if(A[i] <B[j]){
                   i++;
               }
               //if b element is smaller than c j++  y<z
               else if(B[j] <C[k]){
                   j++;
               }
               //c is smaller 
               else{
                   k++;
               }
           }
           return ans;
        }


};

//{ Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}
// } Driver Code Ends