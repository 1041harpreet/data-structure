#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;
int first(vector<int> &arr, int n, int k) {
  int s = 0;
  int e = n - 1;
  int ans = -1;
  int mid = s + (e - s) / 2;
  while (s <= e) {
    if (arr[mid] == k) {
      ans = mid;
      e = mid - 1; // for first occurance
    } else if (k > arr[mid]) {
      s = mid + 1;
    } else if(k<arr[mid]) {
      e = mid - 1;
    }
    mid = s + (e - s) / 2;
  }
  return ans;
}

int second(vector<int> &arr, int n, int k) {
  int s = 0;
  int e = n - 1;
  int ans = -1;
  int mid = s + (e - s) / 2;
  while (s <= e) {
    if (arr[mid] == k) {
      ans = mid;
      s = mid + 1; // for last occurance
    }
    else if (k > arr[mid]) {
      s = mid + 1;
    } else if(k<arr[mid]){
      e = mid - 1;
    }
    mid = s + (e - s) / 2;
  }
  return ans;
}

int countOccurance(vector<int> &arr, int n, int k) {

  int f= first(arr, n, k);
  int l= second(arr, n, k);
  int total=(l-f)+1;
  return total;
}
int main(){
    vector<int> v{1,1,1,2,2,2,3,3,3,3};
    cout<<" occurance is "<<countOccurance(v,10,2);
    return 0;
}