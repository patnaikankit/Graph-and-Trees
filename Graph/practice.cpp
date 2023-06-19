#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> graph[N];
bool vis[N];
vector <int> g[N];
int level[N];

void dfs(int vertex){
    vis[vertex] = true;
    for(auto child: graph[vertex]){
        if(vis[child]){
            continue;
        }
        else{
            dfs(child);
        }
    }
}

void bfs(int source){
    queue<int> q;
    q.push(source);
    vis[source] = 1;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        for(auto child: g[front]){
            if(!vis[child]){
                q.push(child);
                vis[child] = 1;
                level[child] = level[front] + 1;
            }
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
        graph[v].push_back(u);

        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    bfs(1);
    return 0;
}