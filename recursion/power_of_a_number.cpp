#include<iostream>
using namespace std;
int powerOfNumber(int n,int m){
    //n^m
    if(m==0){
        return 1;
    }
    if(m==1){
        return n;
    }
    int t=powerOfNumber(n,m/2);
    if(m %2==0){
        return t*t;
        //even case
    }else{
        return n *t*t;
        //odd case
    }
}
int main(){
    cout<<powerOfNumber(3,1)<<endl;
    return 0;
}