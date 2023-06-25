// Minimum spanning tree
// Given a graph, form a tree using the edges of this graph such that the sum of the edges is minimum
// 1. sort the edges of the graph 
// 2. start connecting the nodes by adding the smallest edge in the same place as that of the graph
// 3. if on adding an edge a loop is forming then don't add that edge
// 4. stop when all the edges are connected
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int parent[N], size[N];

void make(int num){
    parent[num] = num;
    size[num] = 1;
}

int find(int node){
    if(node == parent[node]){
        return node;
    }
    return parent[node] = find(parent[node]);
}

void Union(int node1, int node2){
    node1 = find(node1);
    node2 = find(node2);
    if(node1 != node2){
        if(size[node1] < size[node2]){
            swap(node1, node2);
        }
        parent[node2] = node1;
        size[node1] += size[node2];
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int, pair<int,int>>> edges;
    for(int i = 0; i < m; i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        edges.push_back({wt, {u,v}});
    }
    sort(edges.begin(),edges.end());
    for(int i = 1; i <= n; i++){
        make(i);
    }
    int sum = 0;
    for(auto edge: edges){
        int wt = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        // if two nodes have the same parent then a loop is forming so discard that edge
        if(find(u) == find(v)){
            continue;
        }
        Union(u,v);
        sum += wt;
        cout<<u<<", "<<v<<" -> "<<wt<<endl;
    }
    cout<<sum<<endl;
    return 0;
}