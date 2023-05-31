#include <iostream>
using namespace std;
void duplicateValues(string str)
{
    int l = str.length();
    for (int i = 0; i < l ; i++)
    {
        int count=0;
        for (int j = i + 1; j < l; j++)
        {
            if (str[i] == str[j]&& str[i] !=' ')
            {
                count++;
                str[j]='0';
            }
        }
        if(count>=1 && str[i] !='0'){
            cout<<str[i]<<" ";
        }
    }
}
int main()
{
    string a = "abcdefabsaaabc";
    duplicateValues(a);
    return 0;
}