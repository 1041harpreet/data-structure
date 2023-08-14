// //{ Driver Code Starts
// #include<bits/stdc++.h>
// using namespace std;

// // } Driver Code Ends
// class Solution {
// public:
//     vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
//         vector<vector<int>> results;
//         vector<pair<int,int>> v;
//         //make a pair and insert into a vector
//          for(int i=0;i<intervals.size();i++){
//              v.push_back(make_pair(intervals[i][0],intervals[i][1]));
//          }
//          //sort this vector of pair
//          sort(v.begin(),v.end());
         
//          //check all and insert into ans results vector
//          int i=1,f=v[0].first,s=v[0].second;
//          while(i<v.size()){
//              if(v[i].first<=s){
//                  //means next first element is smaller than prev second element , means combine it
//                  s=max(v[i].second,s);
//              }else{
//                  //first element is larger than previous second element , means dont combine
//                  results.push_back({f,s});
//                  f=v[i].first;
//                  s=v[i].second;
//                  }
//                  i++;
//          }
//          results.push_back({f,s});
//          return results;
//     }
// };

// //{ Driver Code Starts.
// int main(){
// 	int tc;
// 	cin >> tc;
// 	while(tc--){
// 		int n;
// 		cin >> n;
// 		vector<vector<int>>Intervals(n);
// 		for(int i = 0; i < n; i++){
// 			int x, y;
// 			cin >> x >> y;
// 			Intervals[i].push_back(x);
// 			Intervals[i].push_back(y);
// 		}
// 		Solution obj;
// 		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
// 		for(auto i: ans){
// 			for(auto j: i){
// 				cout << j << " ";
// 			}
// 		}
// 		cout << "\n";
// 	}
// 	return 0;
// }
// // } Driver Code Ends