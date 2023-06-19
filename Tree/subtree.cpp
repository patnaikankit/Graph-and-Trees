// Find the subtree sum and the number of even elements in each subtree
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> graph[N];
int subtree_sum[N];
int even_count[N];


void dfs(int vertex, int parent){
    // action on vertex after entering the vertex
    subtree_sum[vertex] += vertex;
    if(vertex%2 == 0){
        even_count[vertex]++;
    }
    for(int child : graph[vertex]){
        // action on child before entering the child
        if(child == parent){
            continue;
        }
        else{
            dfs(child, vertex);
            // action on child after exiting the child
            subtree_sum[vertex] += subtree_sum[child];
            even_count[vertex] += even_count[child];
        }
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
        cout<<i<<" -> "<<subtree_sum[i]<<", "<<even_count[i]<<endl;
    }
    // int q;
    // cin>>q;
    // while(q--){
    //     int v;
    //     cin>>v;
    //     cout<<v<<" -> "<<subtree_sum[v]<<", "<<even_count[v]<<endl;
    // }
    return 0;
}