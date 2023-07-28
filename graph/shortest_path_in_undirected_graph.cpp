#include <unordered_map>
#include <vector>
#include <list>
#include<queue>
#include<algorithm>
using namespace std;
vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t) {
    // Make an adjacency list to store u->v & v->u
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;

    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    // Do BFS
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        for (auto neighbour : adjList[front]) {
            if (!visited[neighbour]) {
                visited[neighbour] = true;
                parent[neighbour] = front;
                q.push(neighbour);
            }
        }
    }
  //now our parent vector is ready , find the distance 
  vector<int> distance;
  int curr=t;
  distance.push_back(t);
  while(curr !=s){
	  curr=parent[curr];
	  distance.push_back(curr);
  }
   reverse(distance.begin(),distance.end());
   return distance;
}
