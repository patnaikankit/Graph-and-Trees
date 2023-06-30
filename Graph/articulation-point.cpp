// An articulation point in a graph refers to a node which when removed will make the graph disconnected, i.e it will increase the number of connected components
// the logic used in finding a bridge of a graph will be used here as well
// here the root node needs to be handled separately 
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> graph[N];
int vis[N];

int min(int x, int y){
    if(x > y){
        return y;
    }
    return x;
}

void dfs(int cur_v, int parent, int &timer,  vector<int> &disc,  vector<int> &low, vector<int> &ans, vector<int> graph[], int vis[]){
    vis[cur_v] = 1;
    disc[cur_v] = low[cur_v] = timer++;
    int neighbour = 0;
    for(auto child: graph[cur_v]){
        if(child == parent){
            continue;
        }
        else if(!vis[child]){
            dfs(child, cur_v, timer, disc, low, ans, graph, vis);
            // if shorter path is found for the child node then traverse that path and update the lowest time of the parent node
            low[cur_v] = min(low[cur_v], low[child]);
            // check for articulation point
            // if the first statement of the if condition is true then it signifies that there is only one way of reaching the child node that is via the parent node hence it can be separated from the graph
            if(low[child] >= disc[cur_v] && parent != -1){
                ans[cur_v] = 1;
            }
            neighbour++;
        }
        else{
            // back edge - while considering a shorter path for the child node
            low[cur_v] = min(low[cur_v], disc[child]);
        }
    }
    if(parent == -1 && neighbour > 1){
        ans[cur_v] = 1; 
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
    vector<int> ans(n);
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            dfs(i, parent, timer, disc, low, ans, graph, vis);
        }
    }
    int count = 0;
    for(int i = 0; i < ans.size(); i++){
        if(ans[i] != 0){
            count++;
        }
    }
    cout<<"Answer ->"<<endl;
    cout<<"Number of articulation points: "<<count<<endl;
    for(int i = 0; i < ans.size(); i++){
        if(ans[i] != 0){
            cout<<i<<endl;
        }
    }
    return 0;
}