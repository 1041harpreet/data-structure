#include <iostream>
#include<stack>
using namespace std;
void reverseString(string str){
    stack<char> s;
    int i=0;
    int len=str.length();
    while (i <len)
    {
       s.push(str[i]);
       i++; 
    }
    while (!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    
    
}
int main()
{
   string str="hello world";
   reverseString(str);
    return 0;
}