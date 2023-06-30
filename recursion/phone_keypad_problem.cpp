#include <iostream>
using namespace std;
#include <vector>
void solution(vector<string> &ans, string output, int index, string mapp[], string str)
{
    // base case
    if (str.length() == index)
    {
        cout << "output is now " << output << endl;
        ans.push_back(output);
        return;
    }

    int number = str[index] - '0';
    string value = mapp[number];
    for (int i = 0; i < value.length(); i++)
    {
        char ch = value[i];
        output.push_back(ch);
        solution(ans, output, index + 1, mapp, str);
        output.pop_back();
    }
}
vector<string> phoneKeypadProblem(string str)
{
    // '23'

    vector<string> ans;
    if (str.length() == 0)
    {
        return ans;
    }
    string output = "";
    int index=0;
    string mapp[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    solution(ans, output, index, mapp, str);
    return ans;
}
int main()
{

    vector<string> v = phoneKeypadProblem("23");

    for (auto i : v)
    {
        cout << i << " ";
    }

    return 0;
}