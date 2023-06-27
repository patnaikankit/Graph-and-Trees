// Directed graph using dfs
// The logic applied for undirected cannot be used because it doesn't account for the fact that directions are used so if a loop is present and it can't be traversed still it will show that there is a loop present
// here we need a dfsvisited array that will track dfs calls for us
// we will mark the dfsvisited as true once it is called and will mark it false while backtracking
// if at any given instant the visited array and the dfsvisited array of a node are true then a cycle is present
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> graph[N];
int vis[N], dfsVisited[N];

bool dfs(int cur_v, int vis[], int dfsVisited[], vector<int> graph[]){
    vis[cur_v] = true;
    dfsVisited[cur_v] = true;
    for(auto child: graph[cur_v]){
        if(!vis[child]){
            bool loop = dfs(child, vis, dfsVisited, graph);
            if(loop){
                return true;
                break;
            }
        }
        else if(dfsVisited[child]){
            return true;
        }
    }
    dfsVisited[cur_v] = false;
    return false;
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 0; i < m; i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
    }
    bool cycle;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            cycle = dfs(i, vis, dfsVisited, graph);
            if(cycle){
                break;
            }
        }
    }
    cout<<cycle<<endl;
    return 0;
}