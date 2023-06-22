// Used in order to find the shortest distance in a weighted graph
// initially all the distances are marked as infinity
// We put each node in priority queue and mark it visited(if not visited else skip) and calculate its distance from the root node
// after that we visit each of the child node and calculate the distance from the root 
// if it can be minimized we will assign this new value to that node and that node to the queue
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int INF = 1e9 + 7;
vector<pair<int, int>> graph[N];

void dijkstra(int source){
    vector<int> vis(N, 0);
    vector<int> distance(N, INF);
    set<pair<int, int>>st;
    st.insert({0, source});
    distance[source] = 0;
    while (st.size() > 0){
        auto node = *st.begin();
        int cur_node = node.second;
        int dist = node.first;
        st.erase(st.begin());
        if(vis[cur_node]){
            continue;
        }
        vis[cur_node] = 1;
        for(auto child: graph[cur_node]){
            int child_node = child.first;
            int wt = child.second;
            if(distance[cur_node] + wt < distance[child_node]){
                distance[child_node] = distance[cur_node] + wt;
                st.insert({distance[child_node], child_node});
            }
        }
    } 
};


int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 0; i < m; i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        graph[u].push_back({v,wt});
    }
    return 0;
}