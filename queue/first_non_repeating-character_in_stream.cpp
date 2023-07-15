#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;
string nonRepeatingCharacter(string str)
{
    if (str.length() == 1)
    {
        return str;
    }
    unordered_map<char, int> count;
    queue<char> q;
    string s = "";
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        count[ch]++;
        q.push(ch);
        while (!q.empty())
        {
            if (count[q.front()] > 1)
            {
                q.pop();
            }
            else
            {
                s.push_back(q.front());
                break;
            }
        }
        if (q.empty())
        {
            s.push_back('#');
        }
    }
    return s;
}
int main()
{
    string str="aabc";
    cout<<nonRepeatingCharacter(str)<<endl; // Output: "a#bb"
    return 0;
}