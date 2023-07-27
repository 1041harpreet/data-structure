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

  // traverse all groups
  vector<bool> visited(v);
  stack<int> s;
  for (int i = 0; i < v; i++) {
    if (!visited[i]) {
      topoSort(i, visited, s, adjList);
    }
  }

  vector<int> ans;
  while (!s.empty()) {
    ans.push_back(s.top());
    s.pop();
  }
  return ans;
}
