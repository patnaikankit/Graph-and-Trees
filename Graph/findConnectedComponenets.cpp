#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> graph[N];
bool vis[N];

// to represent the connected components
// cc will store all the components
// current_cc will store elements of the current component
vector<vector<int>> cc;
vector<int> current_cc;

void dfs(int vertex){
    current_cc.push_back(vertex);
    vis[vertex] = true;
    for(auto child: graph[vertex]){
        if(vis[child]){
            continue;
        }
        else{
            dfs(child);
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
    int count = 0;
    for(int i = 1; i <= n; i++){
        if(vis[i]){
            continue;
        }
        else{
            current_cc.clear();
            dfs(i);
            cc.push_back(current_cc);
            count++;
        }
    }
    cout<<count<<endl;
    for(auto  it: cc){
        for(auto vertex: it){
            cout<<vertex<<" ";
        }
        cout<<endl;
    }
}