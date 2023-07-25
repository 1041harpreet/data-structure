#include <bits/stdc++.h> 
#include<unordered_map>
#include<vector>
void makeAdjList(unordered_map<int,set<int> >&adjList,
 vector<pair<int, int>> &edges){
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;
        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}
void bfs(unordered_map<int,set<int> >&adjList, unordered_map<int,bool> &visited,
        vector<int>&ans, int  node ){
            queue<int>q;
            q.push(node);
            visited[node]=1;
            while(!q.empty()){
                int front=q.front();
                q.pop();

                ans.push_back(front);
                for(auto i: adjList[front]){
                    if(!visited[i]){
                        q.push(i);
                        visited[i]=1;
                    }
                }
            }
}
vector<int> BFS(int vertex, vector<pair<int,int>> edges)
{

    vector<int>ans;
    unordered_map<int,set<int> >adjList;
    unordered_map<int,bool>visited;
    //1. make a adj list which contains 1->0,2 ,2->3,4 like this u->v
    makeAdjList(adjList,edges);

    //traverse all comonents of graph , graph is disconnected 
    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            bfs(adjList,visited,ans,i);
        }
    }
    return ans;
}