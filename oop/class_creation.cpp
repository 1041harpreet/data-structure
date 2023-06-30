#include<iostream>
using namespace std;
class Intro{
    int id;

    int a;
};
int main(){
    Intro intro;
    Intro *i=new Intro;
    cout<<sizeof(i);
    cout<<sizeof(Intro);
    // cout<<intro.id<<endl;
    return 0;
}