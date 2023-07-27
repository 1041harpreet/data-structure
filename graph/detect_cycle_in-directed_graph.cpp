#include <list>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
bool isCyclePresent( int node,unordered_map<int, bool> &visited,unordered_map<int, bool> &dfsVisited,
                    unordered_map<int, list<int>> &adjList) {
  visited[node] = true;
  dfsVisited[node]=true;
  for (auto neighbour : adjList[node]) {
    if (!visited[neighbour]) {
      bool iscycle = isCyclePresent(neighbour, visited,dfsVisited, adjList);
      if (iscycle) {
        return true;
      }
    } else if ( dfsVisited[neighbour]) {
      return true;
    }
  }
  dfsVisited[node]=false;
  return false;
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // make a adjacent list
  unordered_map<int, list<int>> adjList(n);
  for (int i = 0; i < edges.size(); i++) {
    int u = edges[i].first;
    int v = edges[i].second;
    adjList[u].push_back(v);
  }

  // traverse all group
  unordered_map<int, bool> visited;
  unordered_map<int,bool>dfsVisited;
  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      bool isCycle = isCyclePresent(i, visited,dfsVisited, adjList);
      if (isCycle) {
        return true;
      }
    }
  }
  return false;
}