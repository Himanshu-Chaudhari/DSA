#include<iostream>
#include<list>
#include<queue>
using namespace std;

// Topological sort using ---- kann's ---- algorithm
// Write indegree of all nodes
// add all the nodes with zero indegree to a queue
// do BFS
// n = vertices , e = edges

vector<int> topologicalSort(vector<vector<int>> edges,int n,int e){
    unordered_map<int,list<int,int>> adj;
    vector<int> indegree(n+1,0);
    for(int i=0 ; i < e ; i++ ){
        adj[edges[i][0]].push_back(edges[i][1]);
        indegree[edges[i][1]]++;
    }
    queue<int> q;
    for(auto i:indegree){
        if(i==0){
            q.push(i);
        }
    }
    vector<int> ans;
    while(!q.empty()){
        int front=q.front();
        q.pop();
        for(auto neighbour: adj[front]){
            indegree[neighbour]--;
            if(indegree[neighbour]==0){
                q.push(neighbour);
            }
        }
        ans.push_back(front);
    }
    return ans;
}
int main(){
    return 0;
}