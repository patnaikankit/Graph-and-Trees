#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> graph[N];
int vis[N];
int level[N];

void bfs(int source){
    queue<int> q;
    q.push(source);
    vis[source] = 1;
    while(!q.empty()){
        int cur_v = q.front();
        q.pop();
        cout<<cur_v<<" ";
        for(int child: graph[cur_v]){
            if(!vis[child]){
                q.push(child);
                vis[child] = 1;
                level[child] = level[cur_v] + 1;
            }
        }
    }
    cout<<endl;
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
    bfs(1);
    for(int i = 1; i <= n; i++){
        cout<<i<<" : "<<level[i]<<endl;
    }
    return 0;
}