#include <iostream>
#include <unordered_map>
using namespace std;
void threePairSum(int arr[], int size, int s)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            for (int k = j + 1; k < size; k++)
            {
                if (arr[i] + arr[j] + arr[k] == s)
                {
                    cout << arr[i] << " " << arr[j] << " " << arr[k] << endl;
                }
            }
        }
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 4, 9};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    threePairSum(arr, arr_size, 8);
    return 0;
}

// #include<set>

// vector<vector<int>> findTriplets(vector<int>arr, int n, int K)  {

//     // Set to keep the track of visited triplets.
//     set<vector<int>>visited;
//     vector<vector<int>>ans;
//     for (int i = 0; i < n - 2; i++) {
//         for (int j = i + 1; j < n - 1; j++) {
//             for (int k = j + 1; k < n; k++) {
//                 // If we find a valid triplet.
//                 if (arr[i] + arr[j] + arr[k] == K) {
//                     vector<int> triplet;
//                     triplet.push_back(arr[i]);
//                     triplet.push_back(arr[j]);
//                     triplet.push_back(arr[k]);
//                     // Sorting the triplet track distinct triplets.
//                     sort(triplet.begin(), triplet.end());
//                     if (visited.find(triplet) == visited.end()) {
//                         ans.push_back(triplet);
//                         visited.insert(triplet);
//                     }
//                 }
//             }
//         }
//     }

//     return ans;

// }