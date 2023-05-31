#include<iostream>
using namespace std;
bool isPalindrome(string str){
    int l=str.length();
   
    for (int i = 0; i < l/2; i++)
    {
       if (str[i] != str[l-i-1]){
        return false;
       }
    }
    return true;
}
int main(){
    string str="abaaba";
    bool b=isPalindrome(str);
    cout<< b ;
    return 0;
}