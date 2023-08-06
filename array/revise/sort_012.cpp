// 1 check how many 0,1,2 then place that digits 
#include <bits/stdc++.h>
using namespace std;
void sort012(int *arr, int n) {
  int zeroP=0;
  int oneP=0;
  int twoP=n-1;
  while(oneP <=twoP){
    if(arr[oneP]==2){
      swap(arr[oneP],arr[twoP]);
      twoP--;
    }
    else if(arr[oneP]==0){
      swap(arr[oneP],arr[zeroP]);
      zeroP++;
      oneP++;
    }
    else{
      oneP++;
    }
  }
}