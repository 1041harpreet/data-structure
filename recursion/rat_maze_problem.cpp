// Input:
// N = 4
// m[][] = {{1, 0, 0, 0},
//          {1, 1, 0, 1},
//          {1, 1, 0, 0},
//          {0, 1, 1, 1}}
// Output:
// DDRDRR DRDDRR
// Explanation:
// The rat can reach the destination at
// (3, 3) from (0, 0) by two paths - DRDDRR
// and DDRDRR, when printed in sorted order
// we get DDRDRR DRDDRR.
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
bool isSafe(int newx, int newy, int n, vector<vector<int>> visited, vector<vector<int>> v)
{
    if ((v[newx][newy] == 1) && (newx < n && newx >= 0) && (newy < n && newy >= 0) && visited[newx][newy] == 0)
    {
        return true;
    }
    return false;
}
void solution(vector<string> &ans, vector<vector<int>> &v, int n, int x, int y, string st, vector<vector<int>> visited)
{

    // base case
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(st);
        return;
    }
    // set path to tracked
    visited[x][y] = 1;

    cout<<"value of x ,y "<<x<<" "<<y<<endl;
    // down
    int newx = x + 1;
    int newy = y;
    if (isSafe(newx, newy, n, visited, v))
    {
        cout<<"D"<<endl;
        st.push_back('D');
        solution(ans, v, n, newx, newy, st, visited);
        st.pop_back();
    }
    // up
    newx = x - 1;
    newy = y;
    if (isSafe(newx, newy, n, visited, v))
    {
        cout<<"U"<<endl;
        st.push_back('U');
        solution(ans, v, n, newx, newy, st, visited);
        st.pop_back();
    }
    // right
    newx = x;
    newy = y + 1;
    if (isSafe(newx, newy, n, visited, v))
    {
        cout<<"R"<<endl;
        st.push_back('R');
        solution(ans, v, n, newx, newy, st, visited);
        st.pop_back();
    }
    // left
    newx = x;
    newy = y - 1;
    if (isSafe(newx, newy, n, visited, v))
    {
        cout<<"L";
        st.push_back('L');
        solution(ans, v, n, newx, newy, st, visited);
        st.pop_back();
    }

    // set untrack
    visited[x][y] = 0;
}
vector<string> ratPath(vector<vector<int>> &v, int n)
{
    vector<string> ans;
    if (v[0][0] == 0)
    {
        return ans;
    }
    string s = "";
    int x = 0;
    int y = 0;
    vector<vector<int>> visited = v;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = 0;
        }
    }

    solution(ans, v, n, x, y, s, visited);
    // sort(ans.begin(), ans.end());
    return ans;
}

int main()
{

    int N = 4;
    vector<vector<int>> m = {{1, 0, 0, 0},
                             {1, 1, 0, 1},
                             {1, 1, 0, 0},
                             {0, 1, 1, 1}};
    vector<string> v = ratPath(m, N);
    for (auto i : v)
    {
        cout << i << " ";
    }
    return 0;
}
