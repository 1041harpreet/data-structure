#include <iostream>
#include <map>
using namespace std;
// char maximumOccurance(string s,int n){
//     int max=0;
//     char a;
//     map<char,int>m;
//     for (int i = 0; i < n; i++)
//     {
//         char c=s[i];
//         m[c]++;
//     }
//     for(auto i: m){
//         if(i.second>max){
//             max=i.second;
//             a=i.first;
//         }
//     }

//     return a;
// }
char maximumOccurance(string s, int n)
{
    int arr[26] = {};
    int number = 0;
    char ch;
    for (int i = 0; i < n; i++)
    {
        ch = s[i];
        number = ch - 'a';
        arr[number]++;
    }
    int max = -1;
    for (int i = 0; i < 26; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
            ch = i + 'a';
        }
    }
    return ch;
}

int main()
{
    string s = "helloohsss";
    int n = s.length();
    cout << maximumOccurance(s, n);
    return 0;
}