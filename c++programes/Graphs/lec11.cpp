#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;

// Bridges in a graph
// Given an undirected graph of V vertices and E edges. Your task is to find all the bridges in the given undirected graph. A bridge in any graph is defined as an edge which, when removed, makes the graph disconnected](or more precisely, increases the number of connected components in the graph).
// v=vertices and e=edges

void DFS(unordered_map<int,list<int>> &adj,int node,int parent,int &timer,vector<int> &dist,vector<int> &low,unordered_map<int,bool>  &vis,vector<vector<int>> &result){

    vis[node]=true;
    dist[node]=low[node]=timer++;

    for(auto ajubaju : adj[node]){
        // Skiping the parent node
        if(ajubaju == parent){
            continue;
        }
        if(!vis[ajubaju]){
            DFS(adj,ajubaju,node,timer,dist,low,vis,result);
            low[node]=min(low[ajubaju],low[node]);
            //Check if bridge is present
            if(low[ajubaju]>dist[node]){
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(ajubaju);
                result.push_back(ans);
            }
        }
        else{
            //node already visited and not the parent of the node
            //Checking the back node .i.e the lowest timmer to reach the node
            low[node]=min(low[node],dist[ajubaju]);
        }
    }
}

vector<vector<int>> findBridge(vector<vector<int>> &edges,int v,int e){

    unordered_map<int,list<int>> adj;
    for(auto i: edges){
        adj[i[1]].push_back(i[0]);
        adj[i[0]].push_back(i[1]);
    }

    // to track the nodes
    int timer=0;

    // to track the possible distance
    vector<int> dist(v,-1);

    // to track the lowest possible distance
    vector<int> low(v,-1);

    //to check node is already visited or not
    unordered_map<int,bool> vis;

    //to track the parent of the node
    int parent=-1;

    //to store ans
    vector<vector<int>> result;

    // DFS 
    for(int i=0;i<v;i++){
        if(!vis[i]){
            DFS(adj,i,parent,timer,dist,low,vis,result);
        }
    }

    return result;
} 
int main(){
    
    return 0;
}