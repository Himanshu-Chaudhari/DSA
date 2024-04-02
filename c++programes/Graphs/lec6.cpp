// Shortest path in an unweighted graph
#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

vector<int> shortestPath(vector<pair<int,int>> edges, int n, int m, int s, int t){
    // create adj list
    unordered_map<int,list<int>> adj;
    for (int i = 0; i < edges.size(); i++){
        adj[edges[i].first].push_back(edges[i].second);
        adj[edges[i].second].push_back(edges[i].first);
    }
    unordered_map<int,bool> visited;
    unordered_map<int,int> parent;
    queue<int> q;
    q.push(1);
    parent[1]=-1;
    visited[1]=true;
    while(!q.empty()){
        int front=q.front();
        q.pop();
        for(auto i : adj[front]){
            if(!visited[i]){
                q.push(i);
                visited[i]=true;
                parent[i]=front;
            }
        }
    }
    vector<int> ans;
    int curr=t;
    while(curr != s){
        ans.push_back(curr);
        curr=parent[curr];
    }
    reverse(ans.begin(),ans.end());
    return ans; 
}

int main(){

}