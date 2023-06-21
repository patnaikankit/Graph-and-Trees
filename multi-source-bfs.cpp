// In multi source bfs we have multiple starting points and we initilize bfs simultaneously from each of these points
// Here we find out multiple root nodes based on the question and apply bfs from all of these root nodes
// visited array is kept to track each node 
// the shortest path between any node and the starting node is used to determine its level because it can be reached fastest from the particular starting node
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
const int INF = 1e9 + 7;
int value[N][N];
int vis[N][N];
int level[N][N];
int n,m;

vector<pair<int, int>> movements = {
    {1, 0}, {-1, 0}, {0, 1}, {0, -1},
    {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
};

bool isValid(int i, int j){
    return i >= 0 && j >= 0 && i < n && j < m; 
}

int bfs(){
    int maxi = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            maxi = max(maxi, value[i][j]);
        }
    }
    queue<pair<int, int>> q;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(maxi == value[i][j]){
                q.push({i, j});
                level[i][j] = 0;
                vis[i][j] = 1;
            }
        }
    }
    int ans = 0;
    while(!q.empty()){
        auto front = q.front();
        int front_x = front.first;
        int front_y = front.second;
        q.pop();
        for(auto movement: movements){
            int child_x = movement.first + front_x;
            int child_y = movement.second + front_y;
            if(isValid(child_x, child_y)){
                continue;
            }
            if(vis[child_x][child_y]){
                continue;
            }
            q.push({child_x, child_y});
            level[child_x][child_y] = level[front_x][front_y] + 1;
            vis[child_x][child_y] = 1;
            ans = max(ans, level[child_x][child_y]);
        }
    }
    return ans;
}

int main(){
    cin>>n>>m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>value[i][j];
        }
    }
    cout<<bfs()<<endl;
    return 0;
}