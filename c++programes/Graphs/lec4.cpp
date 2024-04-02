#include<iostream>
#include<list>
#include<stack>
using namespace std;

// Topological sort using DFS
// Note :- topological sort is used only in valid acyclic graphs 

void getTopologicalSortUsingDfs(int node , unordered_map<int,list<int>> adj , unordered_map<int,bool> &visited , stack<int> &store){
    visited[node]=true;
    for(auto neighbour:adj[node]){
        if(!visited[neighbour]){
            getTopologicalSortUsingDfs(neighbour,adj,visited,store);
        }
    }
    store.push(node);
}

vector<int> topologicalSort(vector<pair<int,int>> edges,int n,int e){
    unordered_map<int,list<int>> adj;
    for(int i=0;i<e;i++){
        adj[edges[i].first].push_back(edges[i].second);
    }
    unordered_map<int,bool> visited;
    stack<int> store;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            getTopologicalSortUsingDfs(i,adj,visited,store);
        }
    }
    vector<int> ans;
    while(!store.empty()){
        ans.push_back(store.top());
        store.pop();
    }
    return ans;
} 
int main(){
    return 0;
}