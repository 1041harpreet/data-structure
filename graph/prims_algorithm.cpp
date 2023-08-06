//  This algorithm always starts with a single node and moves through several adjacent nodes, in order to explore all of the connected edges along the way.

//  guaranteed to find the MST in a connected, it starts by connecting
// Like Kruskal’s algorithm, Prim’s algorithm can be slow on dense graphs with many edges, as it requires iterating over all edges at least once.
// Prim’s algorithm relies on a priority queue, which can take up extra memory and slow down the algorithm on very large graphs.
// The choice of starting node can affect the MST output, which may not be desirable in some applications.

//for minimum spanning tree , spanning tree-> n nodes and n-1 edges
#include <bits/stdc++.h> 
#include <list>
#include <vector>
#include <limits.h>
using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>>& g)
{
    vector<pair<pair<int, int>, int>> ans;
    //create adj list
    vector<list<pair<int, int>>> adjlist(n + 1);
    for (int i = 0; i < g.size(); i++) {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        adjlist[u].push_back(make_pair(v, w));
        adjlist[v].push_back(make_pair(u, w));
    }

    //create three vectors, parent, key, and mst
    vector<int> key(n + 1);
    vector<bool> mst(n + 1);
    vector<int> parent(n + 1);

    //initialize key with int max as starting all are infinite distance 
    for (int i = 0; i <= n; i++) {
        mst[i] = false;
        parent[i] = -1;
        key[i] = INT_MAX;
    }
    //start
    key[1] = 0;
    parent[1] = -1;
    //find min and update 
    for (int i = 1; i <= n; i++) {
        int mini = INT_MAX;
        int u;
        for (int v = 1; v <= n; v++) {
            if (mst[v] == false && key[v] < mini) {
                u = v;
                mini = key[v];
            }
        }
        //mark min as true
        mst[u] = true;
        //check its adjacent
        for (auto it : adjlist[u]) {
            int v = it.first;
            int w = it.second;
            if (mst[v] == false && w < key[v]) {
                parent[v] = u;
                key[v] = w;
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        ans.push_back({ {parent[i], i}, key[i] });
    }
    return ans;
}

