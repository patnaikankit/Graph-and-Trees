// if you take 2 colours and start colouring the nodes in such a way that no 2 adjacent nodes have the same colour 
// a linear graph with no cycles and a graph containing an even length cycle are always bipartite
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> graph[N];
vector<int> colour(N, -1);

bool bipartite(int node, vector<int> graph[]){
    queue<int> q;
    q.push(node);
    colour[node] = 0;
    while(!q.empty()){
        int cur_v = q.front();
        q.pop();
        for(auto child: graph[cur_v]){
            if(colour[child] == -1 || colour[child] == colour[cur_v]){
                return false;
            }
            else if(colour[child] == -1){
                colour[child] = !colour[cur_v];
                q.push(child);
            }
        }
    }
    return true;
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
    cout<<bipartite(1, graph)<<endl;
    return 0;
}
