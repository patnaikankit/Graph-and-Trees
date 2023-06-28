// All the conditions of dijkstra with negactive weights
// negative cycles are not allowed 
// can be used to find negative cycles in a graph
// you have to check for the shortest path by running the following condition n - 1 times in a loop for each node
// if(distance[cur_node] + wt < distance[child_node]){
//     distance[child_node] = distance[cur_node] + wt;
// }
// the (n - 1)th iteration will give us the final answer
// we will run the loop one more time for each node in order to check for negative cycles
// if we do not find any shorter distance then the graph doesn't have a negative cycle
#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
vector<pair<int, pair<int, int>>> graph;


bool bellmanFord(int n, int m, vector<pair<int, pair<int, int>>>& graph) {
    vector<int> distance(n, INF);
    distance[0] = 0;
    // running the loop for each node n - 1 times
    for(int i = 1; i < n; i++){
        for(int j = 0; j < m; j++){
            int u = graph[j].first;
            int v = graph[j].second.first;
            int wt = graph[j].second.second;
            if(distance[u] != INF && distance[u] + wt < distance[v]){
                distance[v] = distance[u] + wt;
            }
        }
    }
    // checking for negative cycle
    for(int j = 0; j < m; j++){
        int u = graph[j].first;
        int v = graph[j].second.first;
        int wt = graph[j].second.second;
        if(distance[u] != INF && distance[u] + wt < distance[v]){
            return true; 
        }
    }
    return false;
} 

int main() {
    int n, m;
    cin>>n>>m;
    for(int i = 0; i < m; i++){
        int u, v, wt;
        cin>>u>>v>>wt;
        graph.push_back({u, {v, wt}});
    }
    bool cycle = bellmanFord(n, m, graph);
    if(cycle){
        cout<<"Graph contains a negative cycle"<<endl;
    } 
    else{
        cout<<"Graph does not contain a negative cycle"<<endl;
    }
    return 0;
}
