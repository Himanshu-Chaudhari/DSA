#include<iostream>
#include<list>
#include<queue>
using namespace std;

class undirectedGraph{
    public:
        vector<pair<int,int> > edges;

        void addEgde(int a,int b){
            edges.push_back({a,b});
            edges.push_back({b,a});
        }
};

vector<int> BFS(int vertex , vector<pair<int,int> > edges){
    
    //Creating adjecency list
    unordered_map<int,list<int> > adjlist;
    unordered_map<int,bool> visited(false);
    vector<int> ans;

    for(auto i : edges){
        adjlist[i.first].push_back(i.second);
        adjlist[i.second].push_back(i.first);
    }

    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            queue<int> q;
            q.push(i);
            visited[i]=true;
            while(!q.empty()){
                int node=q.front();
                ans.push_back(node);
                q.pop();
                for(auto j:adjlist[node]){
                    if(!visited[j]){
                        q.push(j);
                    }
                    visited[j]=true;
                }
            }
        }
    }
    return ans;
}

void dfs(int i,unordered_map<int,bool> &visited,vector<int> &comp,unordered_map<int,list<int> > &adj){
    comp.push_back(i);
    visited[i]=true;

    for(auto j:adj[i]){
        if(!visited[j]){
            dfs(j,visited,comp,adj);
        }
    }
}

vector<vector<int> > DFS(int n,vector<vector<int>> edges){
    unordered_map<int , list<int> > adj;
    for(int i=0;i<edges.size();i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    unordered_map<int,bool> visited;
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    vector<vector<int>> ans;

    for(int i=0;i<n;i++){
        if(!visited[i]){
            vector<int> comp;
            dfs(i,visited,comp,adj);
            ans.push_back(comp);
        }
    }
    return ans;
}

int main(){

    undirectedGraph g;
    g.addEgde(0,2);
    g.addEgde(1,2);
    g.addEgde(2,3);
    g.addEgde(3,1);
    g.addEgde(4,3);
    vector<vector<int>> v(5,vector<int>(2));
    v[0].push_back(2);
    v[1].push_back(2);
    v[2].push_back(3);
    v[3].push_back(1);
    v[4].push_back(3);
    vector<int> ans=BFS(5,g.edges);
    vector<vector<int>> ans2=DFS(5,v);
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
    for(auto i:ans2){
        for(auto j:i){
            cout<<j<<" ";
        }
    }
    return 0;

}