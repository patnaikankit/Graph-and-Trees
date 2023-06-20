// Question regarding deleting an edge of a tree
// the edge is never actually deleted and the subtree sum of every node is precomputed
// if the question requires something besides subtree sum then precompute it
// Once the precomputation is done, calculate every possibilty by comapring the precomputed value of the target node and the root node  
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> graph[N];
int subtree_sum[N];
int val[N];

void dfs(int vertex, int parent = 0){
    // action on vertex after entering the vertex
    subtree_sum[vertex] += val[vertex];
    for(int child : graph[vertex]){
        // action on child before entering the child
        if(child == parent){
            continue;
        }
        else{
            dfs(child, vertex);
            // action on child after exiting the child
            subtree_sum[vertex] += subtree_sum[child];
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
    dfs(1);
    int ans = 0;
    // every comparison is done in reference with the root node 
    for(int i = 2; i <= n; i++){
        int sum1 = subtree_sum[i];
        int sum2 = subtree_sum[1] - sum1;
        ans = max(ans, sum1*sum2);
    }
    cout<<ans<<endl;
    return 0;
}