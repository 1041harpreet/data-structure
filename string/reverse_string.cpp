#include<iostream>
using namespace std;
string reverse(string a){
    int l=a.length();
    // string b;
    for (int i = 0; i < l/2; i++)
    {
       swap( a[i],a[l-i-1]);
    }
    
    return a;
}
// void reverse(string str)
// {
//     for (int i = str.length() - 1; i >= 0; i--)
//         cout << str[i];
       
// }
int main(){
    string a="abcdefgh aaa  sss";
    string b=reverse(a);
    cout<<b;
    return 0;
}