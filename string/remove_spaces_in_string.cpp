#include <iostream>
using namespace std;
void removeSpacesWithNumber(string str, int n)
{
    string temp = "";
    for (int i = 0; i < n; i++)
    {
        if (str[i] == ' ')
        {
            temp.push_back('@');
            temp.push_back('4');
            temp.push_back('0');
        }
        else
        {
            temp.push_back(str[i]);
        }
    }
    for (int i = 0; i < temp.length(); i++)
    {
        cout << temp[i];
    }
}
void removeSpaces(string str, int n)
{
    string temp = "";
    for (int i = 0; i < n; i++)
    {
        if (str[i] == ' ')
        {
        }
        else
        {
            temp.push_back(str[i]);
        }
    }
    for (int i = 0; i < temp.length(); i++)
    {
        cout << temp[i];
    }
}
void removeSpacesWithoutExtraMemory(string str,int n){
    int i=0;
    for (int i = 0; i < n; i++)
    {
        if(str[i]==' '){
            i++;
        }
        cout<<str[i];
    }
}

int main()
{
    string n = "my name is harpreet singh";

    removeSpacesWithoutExtraMemory(n, n.length());
    return 0;
}