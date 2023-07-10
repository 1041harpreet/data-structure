#include <iostream>
#include <stack>
#include <vector>
using namespace std;

 bool knows(vector<vector<int>> M, int n, int a, int b)
{
    if (M[a][b] == 1)
    {
        return true;
    }
    return false;
}

    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> stk;
    for (int i = 0; i < n; i++)
    {
        stk.push(i);
    }

    while (stk.size() > 1)
    {
        int x = stk.top();
        stk.pop();
        int y = stk.top();
        stk.pop();
        if (knows(M, n, x, y))
        {
            stk.push(y);
        }
        else
        {
            stk.push(x);
        }
        
    }
        int ans = stk.top();
        int rowCount = 0;
        int colCount = 0;
        // check a row contain 0 only
        for (int i = 0; i < n; i++)
        {
            if (M[ans][i] == 0)
            {
                rowCount++;
            }
            
        }
        for(int i=0;i<n;i++){
            if (M[i][ans] == 1)
            {
                colCount++;
            }
        }
        if(colCount ==n-1 && rowCount==n ){
            return ans;
        }else{
            return -1;
        }
        

    return ans;
    
    }
int main()
{
    vector<vector<int>> v={
        {}
    };

}