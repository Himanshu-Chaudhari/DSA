#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;

//Darjans Algorithmn 
// For a connected undirected graph, an articiation point or a cut vertex is a vertex in the graph removing which disconnects the graph.
// For a disconnected undirected graph, an articulation point or a cut vertex is a vertex removing which increases the number of connected components.


void DFS(int i,int parent,int &timer,unordered_map<int,list<int>> &adj,
        vector<int> &discovery,vector<int> &low,unordered_map<int,bool> &visited,vector<int> &articulationPoint){
        
    visited[i]=true;
    discovery[i]=low[i]=timer++;
    int child=0;
    for(auto neighbour:adj[i]){
        
        if(neighbour==parent){
            continue;
        }

        if(!visited[neighbour]){
            DFS(neighbour,i,timer,adj,discovery,low,visited,articulationPoint);
            low[i]=min(low[i],low[neighbour]);
            //********** Formula to know if a point is articulation point or not ************
            if(low[i]>=discovery[i] && parent!=-1){
                articulationPoint[i]++;
            }
            child++;
        }
        else{
            low[i]=min(low[i],discovery[neighbour]);
        }
    }
    if(parent==-1 && child>1){
        articulationPoint[i]++;
    }
}


int main(){
    int n=5;
    int e=5;

    vector<pair<int,int>> graph;

    graph.push_back(make_pair(0,3)); 
    graph. push_back(make_pair (3,4)); 
    graph. push_back(make_pair(0,4)); 
    graph. push_back(make_pair(0,1)); 
    graph. push_back(make_pair (1,2));

    unordered_map<int,list<int>> adj;
    for(auto i:graph){
        adj[i.first].push_back(i.second);
        adj[i.second].push_back(i.first);
    }

    int parent=-1;
    vector<int> discovery(n,-1);
    vector<int> low(n,-1);
    unordered_map<int,bool> visited;
    vector<int> articulationPoint(n,0);
    int timer=0;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            DFS(i,parent,timer,adj,discovery,low,visited,articulationPoint);
        }
    }
    for(int i=0;i<n;i++){
        if(articulationPoint[i]!=0){
            cout<<i <<" ";
        }
    }

}


