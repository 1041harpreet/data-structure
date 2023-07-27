#include <bits/stdc++.h>
using namespace std;
void topoSort(int node, vector< bool> &visited, stack<int> &s, unordered_map<int, list<int>> &adjList) {
  visited[node] = true;
  for (auto neighbour : adjList[node]) {
    if (!visited[neighbour]) {
      topoSort(neighbour, visited, s, adjList);
    }
  }
  s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e) {
  // make an adjacency list
  unordered_map<int, list<int>> adjList(v);
  for (int i = 0; i < e; i++) {
    int u = edges[i][0];
    int v = edges[i][1];
    adjList[u].push_back(v);
  }

  queue<int>q;
  //get inorder degree
  vector<int>indeegre(v);
  for(auto i:adjList){
      for(auto j:i.second){
          indeegre[j]++;
      }
  }

  //push 0 indeegree into queue
  for(int i=0;i<v;i++){
      if(indeegre[i]==0){
          q.push(i);
      }
  }
  vector<int> ans;
  //check queue 
  while(!q.empty()){
      int front=q.front();
      q.pop();
      ans.push_back(front);
      for(auto neighbour: adjList[front]){
          indeegre[neighbour]--;
          if(indeegre[neighbour]==0){
              q.push(neighbour);
          }
      }
  }
  return ans;
}
