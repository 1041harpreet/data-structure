#include <iostream>
using namespace std;
int gcd(int a, int b)
{
    int ans = -1;
    for (int i = 2; i <= min(a, b); i++)
    {

        if (a % i == 0 && b % i == 0)
        {
            ans = i;
        }
    }
    return ans;
}
int main()
{
    cout << gcd(48, 72);
    return 0;
}