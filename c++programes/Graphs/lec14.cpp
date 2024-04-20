#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;

int bellmanFord(vector<vector<int>> edges, int n ,int m , int src ,int des){
    vector<int> distance(n+1,1e9);
    distance[src]=0;
    // n-1 times
    for(int i=1;i<=n;i++){
        // traverse on edge list
        for(int i=0;i<m;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            if(distance[u] != 1e9 && (distance[u]+w) < distance[v]){
                distance[v]=distance[u]+w;
            }
        }
    }
    return distance[des];
    //     check for negative cycle
    //     bool flag=0;
    //     for(int i=0;i<m;i++){
    //         int u=edges[i][0];
    //         int v=edges[i][1];
    //         int w=edges[i][2];
    //         if(distance[u] != 1e9 && (distance[u]+w) < distance[v]){
    //             flag=1;
    //         }
    //     }
        // if(flag==1){
        //     return " -ve cycle present ";
        // }
}

int main(){

}