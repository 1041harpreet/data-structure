#include <iostream>
using namespace std;
class base
{
public:
    int a = 12;
};
class base2
{
public:
    int a = 13;
};
class c : public base,public base2
{
public:
    void fun()
    {
        cout << base2::a << " ";
    }
};
int main()
{
    // c obj;
    c obj;
    obj.fun();
    return 0;
}