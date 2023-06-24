#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
// to store the parent/root of each node
int parent[N];
// used for optimization - union by size
// the aim here is to make sure that a smaller set is merged into a bigger set
int size[N];

// it transforms an number into a independent node 
void make(int num){
    parent[num] = num;
    size[num] = 1;
}

// it is used on a node which would return the root of the set that particular node belongs to
int find(int node){
    if(node == parent[node]){
        return node;
    }
    // path compression for optimization
    // while traversing from a node all the nodes which fall between the starting node and the root node are directly joined to the root node
    return parent[node] = find(parent[node]);
}

// it is used on nodes which would join two sets only by their root node so that both the nodes have the same parent
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
    int n,k;
    cin>>n>>k;
    for(int i = 1; i <= n; i++){
        make(i);
    }
    while(k--){
        int u,v;
        cin>>u>>v;
        Union(u,v);
    }
    int connected_comp = 0;
    for(int i = 1; i <= n; i++){
        if(find(i) == i){
            connected_comp++;
        }
    }
    cout<<connected_comp<<endl;
    return 0;
}