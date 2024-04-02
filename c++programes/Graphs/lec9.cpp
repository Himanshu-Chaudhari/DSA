#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;
// TC :- O(n^2) can be also done in O(nlog(n)) using priority queue for calculating mini value 
// Prims :- Used to find MST i.e Minimum (spanning tree)->(Tree which has all vertices of graph and vertices-1 no of edges)

vector<pair<pair<int,int> ,int> > prims(int nodes,int edges,vector<pair<pair<int,int>,int> > g,int src){
    unordered_map<int,list<pair<int,int> > > adj;
    //Creating adj list
    for(auto i:g){
        int u=i.first.first;
        int v=i.first.second;
        int w=i.second;

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    // 1 based indexing i.e. node indexes starts from 1
    vector<int> key(nodes+1,INT_MAX); // used to keep the track of weights of nodes
    vector<bool> mstAdded(nodes+1,false); // used to keep track wether the node is part of mst or not
    vector<int> parent(nodes+1,-1);

    // Algo begins
    key[src]=0;
    parent[src]=-1;

    for(int i=1;i<nodes;i++){
        int mini=INT_MAX;
        int u;
        // Finding the node with min value
        for(int v=1;v<=nodes;v++){
            if(mstAdded[v]==false && key[v]<mini){
                u=v;
                mini=key[v];
            }
        }
        // mark min node as true in mstAdded
        mstAdded[u]=true;
        //check Adjecent nodes
        for(auto it:adj[u]){
             int v=it.first;
             int w=it.second;
             if(mstAdded[v]==false && w<key[v]){
                parent[v]=u;
                key[v]=w;
             }
        }
    }
    vector<pair<pair<int,int> ,int>> result;
    for(int i=2;i<=nodes;i++){
        result.push_back({{parent[i],i},key[i]});
    }
    return result;
}

int main(){

}