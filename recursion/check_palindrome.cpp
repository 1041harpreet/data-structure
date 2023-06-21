#include <iostream>
using namespace std;
bool checkPalindrome(string str, int start, int end)
{
    if (start > end)
    {
        return true;
    }
    if (str[start] != str[end])
    {
        return false;
    }
    else
    {
        return checkPalindrome(str, start + 1, end - 1);
    }

    // return true;
}
int main()
{
    string s = "abbabbba";
    cout << checkPalindrome(s, 0, 6) << endl;
    return 0;
}