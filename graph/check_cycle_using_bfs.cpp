#include <list>
#include <queue>
#include <unordered_map>
#include <vector>
#include<iostream>
using namespace std;
bool isCyclePresent(int node, unordered_map<int, bool> &visited,
                    unordered_map<int, list<int>> &adjList) {
  unordered_map<int, int> parent;
  queue<int> q;
  q.push(node);
  parent[node] = -1;
  visited[node] = 1;
  while (!q.empty()) {
    int front = q.front();
    q.pop();
    for (auto neibhour : adjList[front]) {
      if (visited[neibhour] == true && neibhour != parent[front]) {
        return true;
      } else if (!visited[neibhour]) {
        visited[neibhour] = 1;
        q.push(neibhour);
        parent[neibhour] = front;
      }
    }
  }
  return false;
}
string cycleDetection(vector<vector<int>> &edges, int n, int m) {

  // make a adjacent list
  unordered_map<int,list<int>> adjList(n);
  for (int i = 0; i < m; i++) {
    int u = edges[i][0];
    int v = edges[i][1];
    adjList[u].push_back(v);
    adjList[v].push_back(u);
  }

  // traverse all group
  unordered_map<int, bool> visited;
  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      bool isCycle = isCyclePresent(i, visited, adjList);
      if (isCycle) {
        return "Yes";
      }
    }
  }
  return "No";
}
