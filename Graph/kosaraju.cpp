// Used in directed graphs to find strongly connected components
// first, we have to find the topological sort of the graph - this will provide us the order in which we have to make the dfs calls
// second, we have to take the transpose of the graph - reverse the direction of the edges
// third, start the dfs calls according to the topo sort
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> graph[N];
vector<int> transpose[N];
int vis[N];

void topoSort(int cur_v, int vis[], stack<int> &s,  vector<int> graph[]){
    vis[cur_v] = 1;
    for(auto child: graph[cur_v]){
        if(!vis[child]){
            topoSort(child, vis, s, graph);
        }
    }
    s.push(cur_v);
}

void dfs(int cur_v, int vis[], vector<int> transpose[]){
    vis[cur_v] = 1;
    for(auto child: transpose[cur_v]){
        if(!vis[child]){
            dfs(child, vis, transpose);
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 0; i < m; i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
    }
    // topological sort
    stack<int> s;
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            topoSort(i, vis, s, graph);
        }
    }
    // transpose of the graph
    for(int i = 0; i < n; i++){
        vis[i] = 0;
        for(auto child: graph[i]){
            transpose[child].push_back(i);
        }
    }
    // dfs calls
    int count = 0;
    while(!s.empty()){
        int top = s.top();
        s.pop();
        if(!vis[top]){
            count++;
            dfs(top, vis, transpose);
        }
    }
    cout<<count<<endl;
    return 0;
}