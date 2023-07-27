#include <list>
#include <queue>
#include <unordered_map>
#include <vector>
bool isCyclePresent(int node, int parent, unordered_map<int, bool> &visited,
                    unordered_map<int, list<int>> &adjList) {
  visited[node] = true;
  for (auto neighbour : adjList[node]) {
    if (!visited[neighbour]) {
      bool iscycle=isCyclePresent(neighbour, node, visited, adjList);
      if(iscycle){
        return true;
      }
    } else if (visited[node] && neighbour != parent) {
      return true;
    }
  }
  return false;
}
string cycleDetection(vector<vector<int>> &edges, int n, int m) {

  // make a adjacent list
  unordered_map<int, list<int>> adjList(n);
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
      bool isCycle = isCyclePresent(i, -1, visited, adjList);
      if (isCycle) {
        return "Yes";
      }
    }
  }
  return "No";
}
