#include <iostream>
using namespace std;
#define infinity 9999
#define max 100

class graph{
    int g[max][max];
    int n;

    public:
        graph(){
            n=0;
        }

        void readGraph(){
            int edges;
            cout<<"no of vertices";
            cin>>n;
            cout<<"edges";
            cin>>edges;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    g[i][j]=0;
                }
            }
            int u,v,weight;
            for(int i=0;i<edges;i++){
                cout<<"enter edge ";
                cin>>u>>v>>weight;
                g[u][v]=weight;
            }
            
        }

        int prims(graph &sp){
            int cost[max][max];
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(g[i][j]==0){
                        cost[i][j]=infinity;
                    }
                    else{
                        cost[i][j]=g[i][j];
                    }
                }
            }
            sp.n=n;
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    sp.g[i][j] = 0;

            
        }
};

int main(){
    return 0;
}