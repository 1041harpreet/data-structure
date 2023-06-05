#include <iostream>
using namespace std;
float squareRoot(int num, int precision)
{
    int start = 1;
    int end = num;
    float ans = -1;
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (mid * mid == num)
        {
            ans = mid;
            break;
        }
        if (mid * mid < num)
        {
            
            start = mid + 1;
            ans=mid;
            cout<<"start now "<<start<<endl;
        }
        else
        {
            end = mid - 1;
            cout<<"end now "<<end<<endl;

        }
        mid = start + (end - start) / 2;  
    }
    float increment = 0.1;
    
    for (int i = 0; i < precision; i++) {
        while (ans * ans <= num) {
            ans += increment;
        }
        ans = ans - increment;
        increment = increment / 10;
    }
    return ans;
}
int main()
{
    cout << squareRoot(77, 2);
    return 0;
}