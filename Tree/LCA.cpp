// Lowest Common Ancestor
// Find the parent of each node
// Store the parent of each node starting from the target node till you reach the root node 
// Compare the vectors  
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> graph[N];
int par[N];

void dfs(int vertex, int parent = -1){
    par[vertex] = parent;
    for(int child: graph[vertex]){
        if(child == parent){
            continue;
        }
        dfs(child, vertex);
    }
}

vector<int> path(int vertex){
    vector<int> ans;
    while (vertex != -1){
        ans.push_back(vertex);
        vertex = par[vertex];
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    int n;
    cin>>n;
    for(int i = 0 ; i < n - 1; i++){
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1);
    int x,y;
    cin>>x>>y;
    vector<int> path_x = path(x);
    vector<int> path_y = path(y);
    int mini = min(path_x.size(), path_y.size());
    int lca = -1;
    for(int i = 1; i <= mini; i++){
        if(path_x[i] == path_y[i]){
            lca = path_x[i];
        }
        else{
            break;
        }
    }
    cout<<lca<<endl;
    return 0;
}