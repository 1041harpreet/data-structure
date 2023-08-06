// shortest paths from the source to all vertices in the given graph.
#include <bits/stdc++.h> 
#include <bits/stdc++.h> 
using namespace std;

vector<int> dijkstra(vector<vector<int>>& vec, int vertices, int edges, int source) {
    vector<list<pair<int, int>>> adjList(vertices);
    //prepare adj list
    for (int i = 0; i < edges; i++) {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];
        adjList[u].push_back(make_pair(v, w));
        adjList[v].push_back(make_pair(u, w)); // If it is an undirected graph
    }
    //create distance array with infinite at first
    vector<int> distance(vertices, INT_MAX);
    
    //create a set (dis, node) and get the smallest distance node and add their neighbor nodes
    set<pair<int, int>> st;
    int src = source; // Use the given source node
    distance[src] = 0;
    st.insert(make_pair(0, src));
    
    while (!st.empty()) {
        auto top = *(st.begin());
        int nodeDistance = top.first;
        int node = top.second;
        st.erase(st.begin());
        
        //insert neighbor into stack 
        for (auto neighbor : adjList[node]) {
            //remove old node from stack if new distance is smaller than old
            if (nodeDistance + neighbor.second < distance[neighbor.first]) {
                //remove the old node
                auto record = st.find(make_pair(distance[neighbor.first], neighbor.first));
                if (record != st.end()) {
                    st.erase(record);
                }
                distance[neighbor.first] = nodeDistance + neighbor.second;
                //push into stack
                st.insert(make_pair(distance[neighbor.first], neighbor.first));
            }
        }
    }
    return distance;
}
