#include <list>
#include <unordered_map>
#include <vector>

void makeAdjList(unordered_map<int, list<int>> &adjList,
                 vector<vector<int>> &edges) {
  for (int i = 0; i < edges.size(); i++) {
    int u = edges[i][0];
    int v = edges[i][1];
    adjList[u].push_back(v);
    adjList[v].push_back(u);
  }
}
void dfs(unordered_map<int, list<int>> &adjList,
         unordered_map<int, bool> &visited, vector<int> &component, int i) {
  component.push_back(i);
  visited[i] = true;
  for (auto j : adjList[i]) {
    if (!visited[j]) {
      dfs(adjList, visited, component, j);
    }
  }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges) {
  // vector<int>ans;
  unordered_map<int, list<int>> adjList;
  unordered_map<int, bool> visited;
  // 1. make a adj list which contains 1->0,2 ,2->3,4 like this u->v
  makeAdjList(adjList, edges);
  vector<vector<int>> ans;
  // traverse all comonents of graph , graph is disconnected
  for (int i = 0; i < V; i++) {

    if (!visited[i]) {
      vector<int> component;
      dfs(adjList, visited, component, i);
      ans.push_back(component);
    }
  }
  return ans;
}