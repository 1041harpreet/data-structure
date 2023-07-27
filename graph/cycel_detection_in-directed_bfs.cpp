//we use all code of kahn but with small change, we check if count ==n it
//  then it is valid toplogy and if topology it means it is directed acyclic graph

#include <list>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  unordered_map<int, list<int>> adjList(n);
  for (int i = 0; i < edges.size(); i++) {
    int u = edges[i].first-1;
    int v = edges[i].second-1;
    adjList[u].push_back(v);
  }

  queue<int>q;
  //get inorder degree
  vector<int>indeegre(n);
  for(auto i:adjList){
      for(auto j:i.second){
          indeegre[j]++;
      }
  }

  //push 0 indeegree into queue
  for(int i=0;i<n;i++){
      if(indeegre[i]==0){
          q.push(i);
      }
  }
  int cnt=0;
  //check queue 
  while(!q.empty()){
      int front=q.front();
      q.pop();
      cnt++;
      for(auto neighbour: adjList[front]){
          indeegre[neighbour]--;
          if(indeegre[neighbour]==0){
              q.push(neighbour);
          }
      }
  }
  if(cnt==n){
    return false;
  }else{
    return true;
  }
}