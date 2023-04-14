#include<iostream>
using namespace std;
void reverse(int digit,int len){
    int rev=0;
   while ( digit !=0)
   {
    int d=digit%10;
    if(rev >INT_MAX || rev<INT_MIN){
        return ;
    }
    rev=rev*10+d;
    digit=digit/10;
   }
   cout<<rev;
}
int main(){
    int digit=12345;
    int len=sizeof(digit)/sizeof(0);
    reverse(digit,len);
    return 0;
}