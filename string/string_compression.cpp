#include <iostream>
#include <vector>
using namespace std;

void compression(vector<char>& v)
{
    int n = v.size();
    int i = 0;
    int k = 0;

    while (i < n)
    {
        if (v[i] != v[i + 1])
        {
            cout << v[i];  // Print the character and its count
            // k = 0;  // Reset the count
            i++;
        }
        else
        {
            int count = 0;
            while (v[i] == v[i + 1] && i < n)
            {
                i++;
                count++;
            }
            // i++;
            cout << v[i] << count + 1;  // Print the character and its count
            // k = 0;  // Reset the count
        }
        i++;
    }
}

int main()
{
    vector<char> v{'a', 'a', 'b', 'b', 'b', 'c', 'c', 'd'};
    compression(v);
    return 0;
}
