// A bridge in a graph refers to an edge which when removed will make the graph disconnected, i.e it will increase the number of connected componenets
// to solve this we require a visited, parent, discovery time and lowest time to reach any node vectors
// discovery time will mark the time to reach each node while lowest time will keep track of the minimum time to reach any node 
// they are both going to differ because for any node we have to consider the shortest path required to reach that node
// we will remove each edge and check if the graph becomes disconnected
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> graph[N];
int vis[N];

void dfs(int cur_v, int parent, int &timer,  vector<int> &disc,  vector<int> &low, vector<vector<int>> &ans, vector<int> graph[], int vis[]){
    vis[cur_v] = 1;
    disc[cur_v] = low[cur_v] = timer++;
    for(auto child: graph[cur_v]){
        if(child == parent){
            continue;
        }
        else if(!vis[child]){
            dfs(child, cur_v, timer, disc, low, ans, graph, vis);
            // if shorter path is found for the child node then traverse that path and update the lowest time of the parent node
            low[cur_v] = min(low[cur_v], low[child]);
            // if edge is a bridge
            if(low[child] > disc[cur_v]){
                vector<int> vec;
                vec.push_back(cur_v);
                vec.push_back(child);
                ans.push_back(vec);
            }
        }
        else{
            // back edge - while considering a shorter path for the child node
            low[cur_v] = min(low[cur_v], disc[child]);
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 0; i < m; i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int timer = 0, parent = -1;
    vector<int> disc(N, -1), low(N, -1);
    vector<vector<int>> ans;
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            dfs(i, parent, timer, disc, low, ans, graph, vis);
        }
    }
    cout<<"Answer ->"<<endl;
    cout<<"Number of bridges: "<<ans.size()<<endl;
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[0].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}