#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> pi;

const int MAX_V = 14;
vector<vector<pi>> graph(MAX_V);

void addedge(int x, int y, int cost)
{
    graph[x].emplace_back(cost, y);
    graph[y].emplace_back(cost, x);
}
void displayGraph()
{
    cout << "Graph:" << endl;
    for (int i = 0; i < MAX_V; ++i)
     {
         cout << "Node " << i << ": ";
         for (const auto &neighbor : graph[i])
         {
         int cost, n_node;
         tie(cost, n_node) = neighbor;
         cout << "(" << n_node << ", " << cost << ") ";
         }
         cout << endl;
     }
}

void best_first_search(int actual_Src, int target)
{
     priority_queue<pi, vector<pi>, greater<pi>> pq;
    vector<bool> visited(MAX_V, false);

     pq.push({0, actual_Src});

     while (!pq.empty())
     {
        int cost, x;
        tie(cost, x) = pq.top();
        pq.pop();

        if (visited[x])
            continue;

        visited[x] = true;

        cout << x << " ";
        if (x == target)
            break;

        for (const auto &neighbor : graph[x])
        {
            int n_cost, n_node;
            tie(n_cost, n_node) = neighbor;

            pq.push({n_cost, n_node});
        }
     }
}

int main()
{
     addedge(0, 1, 3);
     addedge(0, 2, 6);
     addedge(0, 3, 5);
     addedge(1, 4, 9);
     addedge(1, 5, 8);
     addedge(2, 6, 12);
     addedge(2, 7, 14);
     addedge(3, 8, 7);
     addedge(8, 9, 5);
    addedge(8, 10, 6);
    addedge(9, 11, 1);
     addedge(9, 12, 10);
     addedge(9, 13, 2);

     int source = 0;
     int target = 9;

     displayGraph();

     cout<<"Our source node is "<<source<<endl;
     cout<<"Our Destination node is "<<target<<endl;

     cout<<"Selected Path :"<<endl;
     best_first_search(source, target);

     return 0;
}