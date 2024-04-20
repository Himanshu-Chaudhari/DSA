#include<iostream>
#include <unordered_map>
#include <map>
#include <queue>
#include <list>
#include <vector>
//max no of edges N
#define N 10 
using namespace std;

class Graph{
    public:
        unordered_map<int , list<int> > adj;
        map<int ,bool> visited;

        void addEdge(int v , int u){
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        void printAdj(){
            for(auto i : adj){
                cout<< i.first <<" -> ";
                for(auto j : i.second){
                    cout<<j<<" , ";
                }
                cout<<endl;
            }
        }

        void BFS(int src){
            vector<bool> visited(N, false);
            vector<int> distance(N,0);
            queue<int> q;
            q.push(src);
            visited[src]=true;
            distance[src]=0;
            vector<int> path;
            while(!q.empty()){
                int u=q.front();
                q.pop();
                path.push_back(u);
                for(auto v: adj[u]){

                    if(!visited[v]){
                        q.push(v);
                        visited[v]=true;
                        distance[v]=distance[u]+1;
                    }
                }
            }
            cout<<"BFS traversal: ";
            for(auto d : path){
                cout<<d<<" ";
            }
            cout<<endl;
        }

        void DFS(int src){
            visited[src]=true;
            cout<<src<<" ";
            list<int> :: iterator i;
            for(i=adj[src].begin(); i!=adj[src].end();++i){
                if(!visited[*i]){
                    DFS(*i);
                }
            }
            cout<<endl;
        }
};


int main(){
    int choice;
    Graph g;
    do{
        cout<<" 1. Add edges"<<endl;
        cout<<" 2. Print Adjacency List"<<endl;
        cout<<" 3. BFS traversal"<<endl;
        cout<<" 4. DFS traversal"<<endl;
        cout<<" 5. Exit"<<endl;
        
        cout<<"Please enter your choice"<<endl;
        cin>>choice;
        switch(choice){

            case 1:
                cout<<"Enter no of edges :"<<endl;
                int edges;
                cin>>edges;
                cout<<"No of vertices :"<<endl;
                int vertices;
                cin>>vertices;
                cout<<"Enter the starting and ending points of the edge "<<endl;
                for(int i=0;i<edges;i++){
                    int u,v;
                    cin>>u>>v;
                    g.addEdge(u,v);
                }
                break;
            
            case 2:
                cout<<" Adj list is: "<<endl;
                g.printAdj();
                cout<<endl;
                break;

            case 3:
                cout<<"Enter the source Vertex for BFS "<<endl;
                int src;
                cin>>src;
                g.BFS(src);
                break;

            case 4:
                cout<<"Enter the source Vertex for DFS "<<endl;
                cin>>src;
                g.DFS(src);
                break;
        }
    }while (choice != 5);
    return 0;
}