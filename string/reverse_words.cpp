//"my name is harpreet singh" -> "singh harpreet is name my".

#include <iostream>
using namespace std;
string reverse(string a, int i, int j)
{
    while (i < j)
    {
        // Swap characters at l and r
        swap(a[i], a[j]);
        i++;
        j--;
    }
    return a;
}
string reverseWords(string s)
{
    int j = 0;
    s.insert(s.end(), ' ');
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == ' ')
        {
            s=reverse(s, j, i - 1);
            j = i + 1;
        }
    }
    s.pop_back();
    s=reverse(s,0,s.length()-1);
    return s;
}
int main()
{
    string s = "my name is harpreet singh";
    cout << reverseWords(s);
    return 0;
}