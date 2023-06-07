#include <iostream>
using namespace std;
void print(string str, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << str[i];
    }
}
string removeOccurance(string str, int n, string sub)
{
   while (str.length() !=0 && str.find(sub) < n)
   {
    str.erase(str.find(sub), sub.length());
   
   }
   return str;
   
}
int main()
{
    string str = "abbaas";
    string sub = "ba";
    cout<<removeOccurance(str, str.length(), sub);
    return 0;
}