// Undirected unweighted/equal weights graph
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> g[N];
int vis[N], parent[N];

void bfs(int source){
    queue<int> q;
    q.push(source);
    vis[source] = 1;
    parent[source] = -1;
    while (!q.empty()){
        int cur_v = q.front();
        q.pop();
        for(int child: g[cur_v]){
            if(!vis[child]){
                vis[child] = 1;
                parent[child] = cur_v;
                q.push(child);
            }
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    int start, end;
    cin>>start>>end;
    for(int i = 0; i < m; i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bfs(1);
    vector<int> vec;
    int cur_node = end;
    vec.push_back(cur_node);
    while(cur_node != start){
        cur_node = parent[cur_node];
        vec.push_back(cur_node);
    }
    reverse(vec.begin(), vec.end());
    for(int i = 0; i < vec.size(); i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
    return 0;
}
