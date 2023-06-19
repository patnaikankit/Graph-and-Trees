#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
const int N = 1e3 + 10;
int adj_matrix[N][N];
template <typename T>


class adj_list{
    public:
    unordered_map<T, vector<T>> adj;
    void addEdge(T u, T v, bool direction){
        adj[u].push_back(v);
        if(direction == 0){
            adj[v].push_back(u);
        }
    }

    void printList(){
        for(auto it: adj){
            cout<<it.first<<" -> ";
            for(auto j: it.second){
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }
};

int main(){
    int n,m;
    cout<<"Enter number of nodes: ";
    cin>>n;
    cout<<"Enter the number of edges: ";
    cin>>m;
    adj_list<int> g;
    for(int i = 0; i < m; i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u, v, 0);
        adj_matrix[u][v] = 1;
        adj_matrix[v][u] = 1;
    }
    g.printList();
    return 0;
}