#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <stack>
using namespace std;

// Shortest distance of all points from a point

class Graph{
    public:
        unordered_map<int,list<pair<int,int> > > graph;
        void addEdge(int s,int e,int w){
            graph[s].push_back(make_pair(e,w));
        }
};

void dfs(unordered_map<int,list<pair<int,int>>> &graph,vector<bool> &visited,stack<int> &s,int node){
    visited[node]=true;
    for(auto neighbours: graph[node]){
        if(!visited[neighbours.first]){
            dfs(graph,visited,s,neighbours.first);
        }
    }
    s.push(node);
}

vector<int> findShortedDistance(unordered_map<int,list<pair<int,int>>> &graph,int nodes,int src){
    // get Topoloical sort
    vector<bool> visited(nodes);
    stack<int> s;
    for(int i=0;i<nodes;i++){
        if(!visited[i]){
            dfs(graph,visited,s,i);
        }
    }

    // Check the weights
    vector<int> weights(nodes,INT_MAX);
    weights[src]=0;
    while(!s.empty()){
        int top=s.top();
        s.pop();
        if(weights[top]!=INT_MAX){
            for(auto neighbour:graph[top]){
                if(weights[neighbour.first] > neighbour.second + weights[top]){
                    weights[neighbour.first]=neighbour.second + weights[top];
                }
            }
        }
    }
    return weights;
}


int main(){
    Graph g;
    g.addEdge(0,1,5);
    g.addEdge(0,2,3);
    g.addEdge(1,2,2);
    g.addEdge(1,3,6);
    g.addEdge(2,3,7);
    g.addEdge(2,4,4);
    g.addEdge(2,5,2);
    g.addEdge(3,4,-1);
    g.addEdge(4,5,-2);
    vector<int> weights=findShortedDistance(g.graph,6,1);
    for(auto i:weights){
        cout<<i<<" ";
    }
}