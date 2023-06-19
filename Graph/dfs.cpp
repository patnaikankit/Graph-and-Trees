#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
bool vis[N];
vector<int> graph[N];

void dfs(int vertex){
    cout<<vertex<<endl;
    vis[vertex] = true;
    // action on vertex after entering the vertex
    for(int child : graph[vertex]){
        cout<<"parent"<<" "<< vertex <<" "<<"child "<<child<<endl;
        // action on child before entering the child
        if(vis[child]){
            continue;
        }
        else{
            dfs(child);
            // action on child after exiting the child
        }
        // action on vertex before exiting the vertex
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 0 ; i < m; i++){
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1);
    return 0;
}