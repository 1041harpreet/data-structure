#include<iostream>
#include<unordered_map>
#include<set>
using namespace std;
// first using set 
// using hash map
void print(int *arr, int n)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
void removeDups(int *arr, int n)
{
    // Hash map which will store the
    // elements which has appeared previously.
    unordered_map<int, bool> mp;
 
    for (int i = 0; i < n; ++i) {
 
        // Print the element if it is not
        // there in the hash map
        if (mp.find(arr[i]) == mp.end()) {
            cout << arr[i] << " ";
        }
 
        // Insert the element in the hash map
        mp[arr[i]] = true;
    }
}
void removeDuplicate(int *arr,int n){
    set<int >st;
    for(int i=0;i<n;i++){
        st.insert(arr[i]);
    }
     for (auto x : st)
        cout << x << " ";
}

int main()
{
    int arr[] = {1,1,1,1,1,1};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    cout << " Array : ";
    print(arr, arr_size);
    cout<<endl;
    removeDuplicate(arr,arr_size);

    return 0;
}

