#include<iostream>
#include<vector>
using namespace std;
//  Kruskals Algo used to find MST and weight of MST
// comparator use to sort the vector in order of their weights
bool compare(vector<int> *firstEdge,vector<int> *secondEdge){
    return firstEdge[2]>secondEdge[2];
}

// This three function depict the logic of Union set 
void makeSet(vector<int> &parent,vector<int> &rank,int n){
    for(int i=0;i<=n;i++){
        parent[i]=i;
        rank[i]=0;
    }
}

int findParent(vector<int> &parent,int node){
    if(parent[node]==node){
        return node;
    }
    return parent[node]=findParent(parent,parent[node]);
}

void makeUnion(int u,int v,vector<int> &parent,vector<int> &rank){
    u=findParent(parent,u);
    v=findParent(parent,v);
    if(rank[u]>rank[v]){
        parent[v]=u;
    }
    else if(rank[v]>rank[u]){
        parent[u]=v;
    }
    else{
        parent[v]=u;
        rank[u]++;
    }
}

// vector has index 0:source 1:destination 2:weight , n=nodes
int minimumSpanningTree(vector<vector<int>>& edges,int n){
    // We arrange the edges in ascending order in order of their weights 
    sort(edges.begin(),edges.end(),compare);
    vector<int> parent;
    vector<int> rank;
    makeSet(parent,rank,n);
    int weight=0;
    for(int i=0;i<edges.size();i++){
        int u=findParent(parent,edges[i][0]);
        int v=findParent(parent,edges[i][1]);
        int w=edges[i][2];
        // if both nodes have same parent then they are already part of mst so we dont add this node else, we go on to add this nodes
        if(u != v){
            weight+=w;
            makeUnion(u,v,parent,rank);
        }
    }
    return weight;
}

int main(){
    return 0;
}