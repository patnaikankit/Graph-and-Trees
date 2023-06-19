// Undirected graph
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> graph[N];
bool vis[N];

bool dfs(int vertex, int parent){
    vis[vertex] = true;
    bool loop = false;
    for(int child: graph[vertex]){
        if(vis[child] && child == parent){
            continue;
        }
        if(vis[child]){
            return true;
        }
        loop |= dfs(child, vertex);
    }
    return loop;
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 0; i < m; i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    bool loop = false;
    for(int i = 1; i <= n; i++){
        if(vis[i]){
            continue;
        }
        if(dfs(i, 0)){
            loop = true;
            break;
        }
    }
    cout<<loop<<endl;
    return 0;
}