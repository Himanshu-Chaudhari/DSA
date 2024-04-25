#include<iostream>
using namespace std;

#define MAX 20;
#define infinity 9999;
class Graph{
    int G[20][20];
    int n;

    public:
        Graph(){
            n=0;
        }

        void readGraph(){
            cout<<"Enter the no of vertices";
            cin>>n;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    G[i][j]=0;
                }
            }
            cout<<"Enter the no egdes";
            int noOfEdges;
            cin>>noOfEdges;
            cout<<"Enter the list of edges";
            int v1,v2,weight;
            for(int i=0;i<noOfEdges;i++){
                cin>>v1>>v2>>weight;
                G[v1][v2]=G[v2][v1]=weight;
            }
        }

        void Dijkstra(int src){
            int cost[20][20];
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(G[i][j]==0){
                        cost[i][j]=infinity;
                    }
                    else{
                        cost[i][j]=G[i][j];
                    }
                }
            }

            int distance[20];
            int from[20];
            int visited[20];
            for(int i=0;i<n;i++){
                distance[i]=cost[src][i];
                from[i]=src;
                visited[i]=0;
            }

            distance[src]=0;
            visited[src]=1;
            int count=1;
            while(count<= n-1){
                
            }


        }
};
int main(){

}