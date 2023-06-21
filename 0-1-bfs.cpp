// Shortest path with weights can't be found out using bfs 
// Nodes which may appear at the same level with different weights are not actually at the same level
// 0-1 bfs is special case where weights are 0 and 1 only - mostly used in graphs
// The intuition is that at any given moment the queue will have nodes of two different levels and based on the weights we will assign them their position
// Edges with weight 0 and pushed at the front while edges with weight 1 are pushed at the back
// A visited array is not used because we may have to compare a visited node having multiple edges with different weights in order to assign it proper location
// In this case a node will at most appear two times in the queue
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int INF = 1e9 + 7;
vector<pair<int, int>> graph[N];
vector<int>level(N, INF);
int n,m;

int bfs(){
    deque<int> dq;
    dq.push_back(1);
    level[1] = 0;
    while(!dq.empty()){
        int cur_v = dq.front();
        dq.pop_front();
        for(auto child: graph[cur_v]){
            int child_v = child.first;
            int wt = child.second;
            if(level[cur_v] + wt < level[child_v]){
                level[child_v] = level[cur_v] + wt;
                if(wt == 1){
                    dq.push_back(child_v);
                }
                else{
                    dq.push_front(child_v);
                }
            }
        }
    }
    return level[n];
}

int main(){
    cin>>n>>m;
    for(int i = 0; i < m; i++){
        int u,v;
        cin>>u>>v;
        if(u == v){
            continue;
        }
        graph[u].push_back({v, 0});
        graph[v].push_back({u, 1});
    }
    cout<<bfs()<<endl;
    return 0;
}