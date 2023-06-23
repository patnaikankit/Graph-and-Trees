// Used to find shortest path between any two nodes - negative allowed
// negative cycle not allowed
// distance array is kept to maintain the distance between the nodes
#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 10;
const int INF = 1e9 + 7;
int dist[N][N];

int main(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i == j){
                dist[i][j] = 0;
            }
            else{
            dist[i][j] = INF;
            }
        }
    }
    int n,m;
    cin>>n>>m;
    for(int i = 0; i < m; i ++){
        int u,v,wt;
        cin>>u>>v>>wt;
        dist[u][v] = wt;
    }
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(dist[i][k] != INF && dist[k][j] != INF){
                    // whenever a kth new node is added the distance from the starting node to the target node via the kth node is calculated by comparing the distances with the existing (k - 1)th node and the new node
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(dist[i][j] == INF){
                cout<<"I"<<" ";
            }
            else{
                cout<<dist[i][j]<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}