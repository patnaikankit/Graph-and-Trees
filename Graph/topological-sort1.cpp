// using dfs
// used in directed acyclic graph
// linear ordering of edges such that for every edge "u -> v" u always appears before v in that ordering
// stack is used so that once we start back tracking we keep adding nodes in such a way that it will guarantee a sequence which will follow the above rule 
// the exit time of any vertex v is always greater than the exit time of any vertex reachable from it (since they were visited either before the call  dfs(v) or during it).
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> graph[N];
int vis[N];

void topoSort(int cur_v, int vis[], stack<int> &s,  vector<int> graph[]){
    vis[cur_v] = 1;
    for(auto child: graph[cur_v]){
        if(!vis[child]){
            topoSort(child, vis, s, graph);
        }
    }
    s.push(cur_v);
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 0; i < m; i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
    }
    stack<int> s;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            topoSort(i, vis, s, graph);
        }
    }
    vector<int> vec;
    while(!s.empty()){
        int top = s.top();
        vec.push_back(top);
        s.pop();
    }
    for(int i = 0; i < vec.size(); i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
    return 0;
}
