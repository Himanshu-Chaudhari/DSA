#include<iostream>
#include<list>
#include<queue>
using namespace std;

// detect cycle in directed graph 
// If visited==true and dfscall==true the cycle is present in the graph 

bool checkCycleDFS(int i,unordered_map<int,bool> &visited,unordered_map<int,bool> &dfsVisited,unordered_map<int,list<int>> map){
    visited[i]=true;
    dfsVisited[i]=true;
    for(auto neighbour : map[i]){
        if(!visited[neighbour]){
            bool cycle=checkCycleDFS(neighbour,visited,dfsVisited,map);
            if(cycle){
                return true;
            }
        }
        else if(dfsVisited[neighbour]){
            return true;
        }
    }
    dfsVisited[i]=false;
    return false;
}

int detectCycleInDirectedGraph(vector<pair<int,int>> &edges,int n){
    unordered_map<int,list<int>> map;
    for(int i=0;i<n;i++){
        map[edges[i].first].push_back(edges[i].second);
    }

    unordered_map<int,bool> dfsVisited;
    unordered_map<int,bool> visited;
    // call dfs for all components
    for(int i=1;i<n;i++){
        if(!visited[i]){
            bool cycle=checkCycleDFS(i,visited,dfsVisited,map);
            if(cycle){
                return true;
            }
        }
    }
    return false;
}
int main(){

    return 0;
}