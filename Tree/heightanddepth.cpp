#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> graph[N];
vector<int> depth(N) , height(N);

void dfs(int vertex, int parent){
    cout<<vertex<<endl;
    // action on vertex after entering the vertex
    for(int child : graph[vertex]){
        // action on child before entering the child
        if(child == parent){
            continue;
        }
        else{
            depth[child] = depth[vertex] + 1;
            dfs(child, vertex);
            // action on child after exiting the child
        }
        height[vertex] = max(height[vertex], height[child] + 1);
        // action on vertex before exiting the vertex
    }
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
    dfs(1, 0);
    for(int i = 1; i <= n; i++){
        cout<<i<<" -> "<<depth[i]<<", "<<height[i]<<endl;
    }
    return 0;
}