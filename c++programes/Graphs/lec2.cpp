#include<iostream>
#include<list>
#include<queue>
using namespace std;

class undirectedGraph{
    public:
        vector<pair<int,int> > edges;

        void addEgde(int a,int b){
            edges.push_back({a,b});
            edges.push_back({b,a});
        }
};

// cycle detection in a undirected graph using bsf

bool solveBFS(unordered_map<int,list<int>> adj,unordered_map<int,bool> &visited,int src){
    unordered_map<int,int> parent;
    parent[src]=-1;
    visited[src]=1;
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int front=q.front();
        q.pop();
        for(auto neighbour : adj[front]){
            if(visited[neighbour] == true && neighbour != parent[front]){
                return true;
            }
            else if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour]=1;
                parent[neighbour]=front;
            } 
        }
    }
}

bool checkCycleBFS(vector<pair<int,int> > edge,int n,int m){
    unordered_map<int,list<int>> adj;
    for(int i=0;i<m;i++){
        adj[edge[i].first].push_back(edge[i].second);
        adj[edge[i].second].push_back(edge[i].first);
    }
    unordered_map<int,bool> visited;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            bool ans=solveBFS(adj,visited,i);
            if(ans){
                return "Yes";
            }
        }
    }
}


// cylce detection using dfs 

bool solveDSF(unordered_map<int,list<int>> adj,unordered_map<int,bool> &visited,int src,int parent){
    visited[src]=true;
    for(auto neighbour: adj[src]){
        if(!visited[neighbour]){
            bool cycleDetected = solveDSF(adj,visited,neighbour,src);
            if(cycleDetected){
                return true;
            }
        }
        else if(neighbour != parent){
            // cycle present
            return true;
        }
    }
    return false;
}

bool checkCycleDSF(vector<pair<int,int> > edge,int n,int m){
    unordered_map<int,list<int>> adj;
    for(int i=0;i<m;i++){
        adj[edge[i].first].push_back(edge[i].second);
        adj[edge[i].second].push_back(edge[i].first);
    }
    unordered_map<int,bool> visited;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            bool ans=solveDSF(adj,visited,i,-1);
            if(ans){
                return "Yes";
            }
        }
    }
}
int main(){

    undirectedGraph g;
    g.addEgde(0,2);
    g.addEgde(1,2);
    g.addEgde(2,3);
    g.addEgde(3,1);
    g.addEgde(4,3);

}