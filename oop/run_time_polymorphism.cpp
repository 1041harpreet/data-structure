#include <iostream>
using namespace std;
class base
{
public:
    void show(){
        cout<<"hello base";
    }
};

class child : public base
{
public:
    void show()
    {
       cout<<"hello c";
    }
};
int main()
{
    child obj;
    obj.show();
    return 0;
}