// #include <iostream>
// using namespace std;
// string removeAdjDup(string str, int n)
// {
//     // base case
//     if (n == 0) {
//         return str;
//     }

//     // `k` maintains the index of the next free location in the result,
//     // and `i` maintains the current index of the string
//     int i, k = 0;
//     int len = str.length();

//     // start from the second character
//     for (i = 1; i < len; i++)
//     {
//         // if the current character is not the same as the
//         // previous character, add it to the result
//         if (str[i - 1] != str[i]) {
//             str[k++] = str[i - 1];
//         }
//         else {
//             // remove adjacent duplicates
//             while (i < len && str[i - 1] == str[i]) {
//                 i++;
//             }
//         }
//     }

//     // add the last character to the result
//     str[k++] = str[i - 1];

//     // null terminate the string
//     str[k] = '\0';

//     // start again if any duplicate is removed
//     if (k != n) {
//         return removeAdjDup(str, k);    // Schlemiel painter’s algorithm
//     }

//     // if the algorithm didn't change the input string, that means
//     // all the adjacent duplicates are removed
//     return str;
// }
// int main()
// {
//     string s = "hello";
//     int n= s.length();
//     cout << removeAdjDup(s,n);
//     return 0;
// }
#include <iostream>
using namespace std;
string removeAdjDup(string str)
{
    int n=str.length();
    // base case
    if (n == 0)
    {
        return str;
    }
    for (int i = 0; i < n; i++)
    {
        if (str[i + 1] == str[i])
        {
            str.erase(i, 2);
            return removeAdjDup(str);
        }
    }

    return str;
}
int main()
{
    string s = "hello";
    int n = s.length();
    cout << removeAdjDup(s);
    return 0;
}