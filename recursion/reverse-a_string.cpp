#include <iostream>
using namespace std;
void reverseString(string& s, int start, int end)
{
    if (start > end)
    {
        return ;
    }
    swap(s[start], s[end]);
    start++;
    end--;
    reverseString(s, start , end );
}
int main()
{
    string str = "gurmeet";
    reverseString(str, 0, 6);
    cout<<str<<endl;
    return 0;
}