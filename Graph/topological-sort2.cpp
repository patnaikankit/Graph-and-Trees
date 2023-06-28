// using kahn's algorithm(bfs)
// used in directed acyclic graph
// an array is maintained to track the indegree of each node 
// we will use a queue where we will put nodes with 0 indegree in it and delete them and start a bfs call from it for it's child node
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> graph[N];
int vis[N];


int main(){
    int n,m;
    cin>>n>>m;
    vector<int> indegree(n + 1, 0); 
    for(int i = 0; i < m; i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        indegree[v]++; 
    }

    queue<int> q;
    for(int i = 1; i <= n; i++){ 
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    vector<int> vec;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        vec.push_back(front);
        for(auto child: graph[front]){
            indegree[child]--;
            if(indegree[child] == 0){
                q.push(child);
            }
        }
    }

    for(int i = 0; i < vec.size(); i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;

    return 0;
}