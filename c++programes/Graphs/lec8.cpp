#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<list>
using namespace std;

// TC:- O(ElogV)  SC:- O(E+V)
//Dijstras
// vector has index 0:source 1:destination 2:weight
// adj list of each element has pairs of the adjacent node and the cost between it and adjacent node
vector<int> Dijstras(vector<vector<int> > v,int nodes,int edges,int src){
    unordered_map<int,list<pair<int,int>>> adj;
    for(auto i:v){
        adj[i[0]].push_back(make_pair(i[1],i[2]));
        adj[i[1]].push_back(make_pair(i[0],i[2]));
    }

    vector<int> distance(nodes,INT_MAX);
    //Instead of set priority queue can also be used here
    set<pair<int,int>> s;
    distance[src]=0;
    s.insert(make_pair(0,src));
    while(!s.empty()){
        // fetching top node of the set
        auto top=*(s.begin());
        s.erase(s.begin());
        int weight=top.first;
        int topNode=top.second;
        for(auto i:adj[topNode]){
            if(distance[i.first] > weight+i.second){
                // checking if the node is already present in the set
                auto it=s.find(make_pair(distance[i.first],i.first));
                if(it!=s.end()){
                    s.erase(it);
                }
                distance[i.first]=weight+i.second;
                s.insert(make_pair(distance[i.first],i.first));
            }
        }
    }
    return distance;
}
int main(){
    // 0 1 7
    // 0 2 1
    // 0 3 2
    // 1 2 3
    // 1 3 5
    // 1 4 1
    // 3 4 7
    vector<vector<int>> v{{0,1,7},{0,2,1},{0,3,2},{1,2,3},{1,3,5},{1,4,1},{3,4,7}};
    vector<int> ans=Dijstras(v,5,7,0);
    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}